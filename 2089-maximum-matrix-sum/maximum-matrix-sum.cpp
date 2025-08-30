class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& A) {
        int n = A.size();

        long long sum = 0;
        int mini = INT_MAX;
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] < 0) {
                    count++;
                }
                mini = min(mini, abs(A[i][j]));
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += abs(A[i][j]);
            }
        }

        if (count % 2 == 1)
            sum -= 2 * mini;
        return sum;
    }
};