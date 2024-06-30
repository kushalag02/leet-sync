class Solution {
public:
    // Review the question again
    vector<int> parentAlice, parentBob;
    vector<int> rankAlice, rankBob;

    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    bool unionSets(vector<int>& parent, vector<int>& rank, int a, int b) {
        int aRoot = find(parent, a);
        int bRoot = find(parent, b);
        if (aRoot != bRoot) {
            if (rank[aRoot] < rank[bRoot]) {
                parent[aRoot] = bRoot;
            } else if (rank[aRoot] > rank[bRoot]) {
                parent[bRoot] = aRoot;
            } else {
                parent[aRoot] = bRoot;
                rank[bRoot]++;
            }
            return true;
        }
        return false;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        parentAlice.resize(n + 1);
        parentBob.resize(n + 1);
        rankAlice.resize(n + 1, 0);
        rankBob.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parentAlice[i] = i;
            parentBob[i] = i;
        }

        int removedEdges = 0;
        int aliceEdges = 0, bobEdges = 0;

        for (auto edge : edges) {
            if (edge[0] == 3) {
                if (unionSets(parentAlice, rankAlice, edge[1], edge[2])) {
                    unionSets(parentBob, rankBob, edge[1], edge[2]);
                    aliceEdges++;
                    bobEdges++;
                } else {
                    removedEdges++;
                }
            }
        }

        for (auto edge : edges) {
            if (edge[0] == 1) {
                if (unionSets(parentAlice, rankAlice, edge[1], edge[2])) {
                    aliceEdges++;
                } else {
                    removedEdges++;
                }
            }
        }

        for (auto edge : edges) {
            if (edge[0] == 2) {
                if (unionSets(parentBob, rankBob, edge[1], edge[2])) {
                    bobEdges++;
                } else {
                    removedEdges++;
                }
            }
        }

        if (aliceEdges != n - 1 || bobEdges != n - 1) {
            return -1;
        }

        return removedEdges;
    }
};
