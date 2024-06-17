class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> diff(n, vector<int>(m, 0));
        vector<int> row1(n, 0);
        vector<int> col1(m, 0);
        vector<int> row0(n, 0);
        vector<int> col0(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    row1[i]++;
                    col1[j]++;
                } else {
                    row0[i]++;
                    col0[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diff[i][j] = row1[i] + col1[j] - row0[i] - col0[j];
            }
        }

        return diff;
    }
};
