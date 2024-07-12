class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);
        if (aRoot != bRoot) {
            if (size[aRoot] < size[bRoot]) {
                parent[aRoot] = bRoot;
                size[bRoot] += size[aRoot];
            } else {
                parent[bRoot] = aRoot;
                size[aRoot] += size[bRoot];
            }
        }
    }

    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n * n);
        size.resize(n * n, 1);
        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++) {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = nrow * n + ncol;
                        unionSets(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int maxIsland = 0;
        for (int i = 0; i < n * n; i++) {
            if (parent[i] == i) {
                maxIsland = max(maxIsland, size[i]);
            }
        }
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    set<int> st;
                    for (int i = 0; i < 4; i++) {
                        int nrow = row + dr[i];
                        int ncol = col + dc[i];
                        if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                            int adjNodeNo = nrow * n + ncol;
                            st.insert(find(adjNodeNo));
                        }
                    }
                    int sizeSum = 1;
                    for (int root : st) {
                        sizeSum += size[root];
                    }
                    maxIsland = max(maxIsland, sizeSum);
                }
            }
        }
        return maxIsland;
    }
};
