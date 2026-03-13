#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100005;
const int INF = 1000000000;

vector<int> graph[MAX_NODES];
bool isWhite[MAX_NODES];

// Centroid decomposition data
bool centroidUsed[MAX_NODES];
int subSize[MAX_NODES];
vector<pair<int,int>> centDist[MAX_NODES]; // for each node: list of (centroid, dist)
multiset<int> centSets[MAX_NODES]; // for each centroid: multiset of distances of white nodes

int compute_subsize(int u, int p) {
    subSize[u] = 1;
    for (int v : graph[u]) if (v != p && !centroidUsed[v]) {
        subSize[u] += compute_subsize(v, u);
    }
    return subSize[u];
}

int find_centroid(int u, int p, int total) {
    for (int v : graph[u]) if (v != p && !centroidUsed[v]) {
        if (subSize[v] > total/2) return find_centroid(v, u, total);
    }
    return u;
}

void dfs_dist_fill(int u, int p, int depth, int cent) {
    centDist[u].push_back({cent, depth});
    for (int v : graph[u]) if (v != p && !centroidUsed[v]) {
        dfs_dist_fill(v, u, depth+1, cent);
    }
}

void build_centroid(int entry, int p) {
    int total = compute_subsize(entry, -1);
    int cent = find_centroid(entry, -1, total);
    centroidUsed[cent] = true;
    // fill distances from centroid to nodes in its component
    dfs_dist_fill(cent, -1, 0, cent);
    for (int v : graph[cent]) if (!centroidUsed[v]) {
        build_centroid(v, cent);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int nodeCount;
    cin >> nodeCount;
    
    for (int edge = 0; edge < nodeCount - 1; edge++) {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        graph[firstNode].push_back(secondNode);
        graph[secondNode].push_back(firstNode);
    }
    
    for (int node = 1; node <= nodeCount; node++) {
        isWhite[node] = false;
        centroidUsed[node] = false;
        centDist[node].clear();
        // centSets[node] is global; ensure empty
        centSets[node].clear();
    }

    // build centroid decomposition (fills centDist)
    build_centroid(1, -1);

    int instructionCount;
    cin >> instructionCount;

    while (instructionCount--) {
        int operationType, nodeIndex;
        cin >> operationType >> nodeIndex;

        if (operationType == 0) {
            // toggle
            if (!isWhite[nodeIndex]) {
                // turn white: insert distances into centroid multisets
                for (auto &pr : centDist[nodeIndex]) {
                    int cent = pr.first;
                    int d = pr.second;
                    centSets[cent].insert(d);
                }
                isWhite[nodeIndex] = true;
            } else {
                // turn black: remove one occurrence from each centroid multiset
                for (auto &pr : centDist[nodeIndex]) {
                    int cent = pr.first;
                    int d = pr.second;
                    auto it = centSets[cent].find(d);
                    if (it != centSets[cent].end()) centSets[cent].erase(it);
                }
                isWhite[nodeIndex] = false;
            }
        } else {
            if (isWhite[nodeIndex]) {
                cout << 0 << "\n";
                continue;
            }
            int ans = INF;
            for (auto &pr : centDist[nodeIndex]) {
                int cent = pr.first;
                int d = pr.second;
                if (!centSets[cent].empty()) {
                    ans = min(ans, d + *centSets[cent].begin());
                }
            }
            if (ans == INF) cout << -1 << "\n";
            else cout << ans << "\n";
        }
    }
    
    return 0;
}
