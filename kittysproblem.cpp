#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAX_NODES = 200005;
const int LOG_HEIGHT = 20;

vector<int> graph[MAX_NODES];
int nodeDepth[MAX_NODES];
int parentTable[MAX_NODES][LOG_HEIGHT];

void buildTree(int currentNode, int parentNode, int currentDepth) {
    nodeDepth[currentNode] = currentDepth;
    parentTable[currentNode][0] = parentNode;
    
    for (int nextNode : graph[currentNode]) {
        if (nextNode != parentNode) {
            buildTree(nextNode, currentNode, currentDepth + 1);
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

int calculateDistance(int firstNode, int secondNode) {
    int lowestCommonAncestor = findLowestCommonAncestor(firstNode, secondNode);
    return nodeDepth[firstNode] + nodeDepth[secondNode] - 2 * nodeDepth[lowestCommonAncestor];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int nodeCount, queryCount;
    cin >> nodeCount >> queryCount;
    
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
        int setSize;
        cin >> setSize;
        vector<int> queryNodes(setSize);
        for (int index = 0; index < setSize; index++) {
            cin >> queryNodes[index];
        }
        
        long long answer = 0;
        if (setSize <= 1000) {
            for (int firstIndex = 0; firstIndex < setSize; firstIndex++) {
                for (int secondIndex = firstIndex + 1; secondIndex < setSize; secondIndex++) {
                    int firstNode = queryNodes[firstIndex];
                    int secondNode = queryNodes[secondIndex];
                    int pathDistance = calculateDistance(firstNode, secondNode);
                    answer = (answer + (long long)firstNode * secondNode % MOD * pathDistance % MOD) % MOD;
                }
            }
        } else {
            vector<pair<int, int>> sortedNodes;
                        vector<long long> prefixSum(setSize + 1);
                        for (int i = 0; i < setSize; i++) {
                            sortedNodes.push_back({nodeDepth[queryNodes[i]], queryNodes[i]});
                        }
                        sort(sortedNodes.begin(), sortedNodes.end());
                        
                        prefixSum[0] = 0;
                        for (int i = 0; i < setSize; i++) {
                            prefixSum[i + 1] = (prefixSum[i] + sortedNodes[i].second) % MOD;
                        }
                        
                        long long firstTerm = 0;
                        for (int i = 0; i < setSize; i++) {
                            long long remainingSum = (prefixSum[setSize] - prefixSum[i + 1] + MOD) % MOD;
                            firstTerm = (firstTerm + (long long)sortedNodes[i].first * sortedNodes[i].second % MOD * remainingSum % MOD) % MOD;
                        }
                        
                        long long secondTerm = 0;
                        vector<bool> isAncestor(setSize);
                        for (int i = 0; i < setSize; i++) {
                            int node = sortedNodes[i].second;
                            long long subtreeSum = 0;
                            for (int j = i + 1; j < setSize && nodeDepth[sortedNodes[j].second] > nodeDepth[node]; j++) {
                                if (findLowestCommonAncestor(node, sortedNodes[j].second) == node) {
                                    subtreeSum = (subtreeSum + sortedNodes[j].second) % MOD;
                                }
                            }
                            secondTerm = (secondTerm + (long long)node * subtreeSum % MOD * nodeDepth[node] % MOD) % MOD;
                        }
            secondTerm = (secondTerm * 2) % MOD;
            
            answer = (firstTerm - secondTerm + MOD) % MOD;
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}
