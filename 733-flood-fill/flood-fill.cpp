class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> temp = image;
        int initial = image[sr][sc];
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, image, temp, delRow, delCol, color, initial);
        return temp;
    }
    void dfs(int sr, int sc, vector<vector<int>>& image,
             vector<vector<int>>& temp, int delRow[], int delCol[], int color,
             int initial) {
        temp[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == initial && temp[nrow][ncol] != color) {
                dfs(nrow, ncol, image, temp, delRow, delCol, color, initial);
            }
        }
    }
};