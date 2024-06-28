class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& A) {
        int n = A.size();
        int m = A[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nRow = r + dr[i];
                int nCol = c + dc[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    A[nRow][nCol] == '1' && !vis[nRow][nCol]) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& A) {
        int n = A.size();
        int m = A[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == '1' && !vis[i][j]) {
                    count++;
                    bfs(i, j, vis, A);
                }
            }
        }
        return count;
    }
};
