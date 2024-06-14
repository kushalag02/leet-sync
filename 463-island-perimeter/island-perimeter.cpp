class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j, grid);
                }
            }
        }
        return 0;
    }
    int dfs(int sr, int sc, vector<vector<int>>& grid) {
        grid[sr][sc] = -1;

        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];

            if (nrow < 0 || ncol < 0 || nrow >= rows || ncol >= cols ||
                grid[nrow][ncol] == 0) {
                perimeter++;
            } else if (grid[nrow][ncol] == 1) {
                perimeter += dfs(nrow, ncol, grid);
            }
        }

        return perimeter;
    }
};
