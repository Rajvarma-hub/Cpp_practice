#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100005;
const int LOG_HEIGHT = 18;

vector<int> graph[MAX_NODES];
int nodeWeight[MAX_NODES];
int nodeDepth[MAX_NODES];
int parentTable[MAX_NODES][LOG_HEIGHT];

void buildTree(int currentNode, int parentNode, int currentDepth) {
    nodeDepth[currentNode] = currentDepth;
    parentTable[currentNode][0] = parentNode;
    
    for (int i = 0; i < (int)graph[currentNode].size(); i++) {
        int neighbor = graph[currentNode][i];
        if (neighbor != parentNode) {
            buildTree(neighbor, currentNode, currentDepth + 1);
        }
    }
}

void precomputeLCA(int nodeCount) {
    for (int level = 1; level < LOG_HEIGHT; level++) {
        for (int node = 1; node <= nodeCount; node++) {
            if (parentTable[node][level - 1] != -1) {
                parentTable[node][level] = parentTable[parentTable[node][level - 1]][level - 1];
            } else {
                parentTable[node][level] = -1;
            }
        }
    }
}

int findLowestCommonAncestor(int firstNode, int secondNode) {
    if (nodeDepth[firstNode] < nodeDepth[secondNode]) {
        swap(firstNode, secondNode);
    }
    
    int depthDifference = nodeDepth[firstNode] - nodeDepth[secondNode];
    for (int bit = 0; bit < LOG_HEIGHT; bit++) {
        if (depthDifference & (1 << bit)) {
            firstNode = parentTable[firstNode][bit];
        }
    }
    
    if (firstNode == secondNode) {
        return firstNode;
    }
    
    for (int bit = LOG_HEIGHT - 1; bit >= 0; bit--) {
        if (parentTable[firstNode][bit] != parentTable[secondNode][bit]) {
            firstNode = parentTable[firstNode][bit];
            secondNode = parentTable[secondNode][bit];
        }
    }
    
    return parentTable[firstNode][0];
}

int findKthMinimumOnPath(int startNode, int endNode, int k) {
    int lowestCommonAncestor = findLowestCommonAncestor(startNode, endNode);
    vector<int> weights;
    
    int currentNode = startNode;
    while (currentNode != lowestCommonAncestor) {
        weights.push_back(nodeWeight[currentNode]);
        currentNode = parentTable[currentNode][0];
    }
    weights.push_back(nodeWeight[lowestCommonAncestor]);
    
    vector<int> pathFromLCA;
    currentNode = endNode;
    while (currentNode != lowestCommonAncestor) {
        pathFromLCA.push_back(nodeWeight[currentNode]);
        currentNode = parentTable[currentNode][0];
    }
    
    for (int i = (int)pathFromLCA.size() - 1; i >= 0; i--) {
        weights.push_back(pathFromLCA[i]);
    }
    
    nth_element(weights.begin(), weights.begin() + k - 1, weights.end());
    return weights[k - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int nodeCount, queryCount;
    cin >> nodeCount >> queryCount;
    
    for (int node = 1; node <= nodeCount; node++) {
        cin >> nodeWeight[node];
    }
    
    for (int edge = 0; edge < nodeCount - 1; edge++) {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        graph[firstNode].push_back(secondNode);
        graph[secondNode].push_back(firstNode);
    }
    
    for (int node = 0; node < MAX_NODES; node++) {
        for (int level = 0; level < LOG_HEIGHT; level++) {
            parentTable[node][level] = -1;
        }
    }
    
    buildTree(1, -1, 0);
    precomputeLCA(nodeCount);
    
    while (queryCount--) {
        int firstNode, secondNode, k;
        cin >> firstNode >> secondNode >> k;
        int result = findKthMinimumOnPath(firstNode, secondNode, k);
        cout << result << "\n";
    }
    
    return 0;
}
