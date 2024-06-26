class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rows(n, 0);
        vector<int> columns(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    rows[i]++;
                    columns[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] && (columns[j] > 1 || rows[i] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};