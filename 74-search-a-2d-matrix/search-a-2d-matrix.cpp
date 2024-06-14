class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        if (A.empty() || A[0].empty()) return false;

        int n = A.size();
        int m = A[0].size();

        int left = 0;
        int right = n * m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int i = mid / m;
            int j = mid % m;
            if (target == A[i][j]) {
                return true;
            } else if (target > A[i][j]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
