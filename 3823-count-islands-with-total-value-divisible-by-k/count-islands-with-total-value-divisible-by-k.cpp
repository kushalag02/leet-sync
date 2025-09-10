class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        if (r < 0 || c < 0 || r >= n || c >= m)
            return 0;
        if (grid[r][c] <= 0 || vis[r][c])
            return 0;

        vis[r][c] = 1;
        long long sum = grid[r][c];

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            sum += dfs(grid, r + drow[i], c + dcol[i], vis);
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long total = dfs(grid, i, j, vis);
                    if (total % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
