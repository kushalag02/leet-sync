class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int n = A.size();
        int m = A[0].size();

        int row = 0;
        int col = m - 1;

        while (row < n && col >= 0) {
            if (A[row][col] == target) {
                return true;
            } else if (A[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};
