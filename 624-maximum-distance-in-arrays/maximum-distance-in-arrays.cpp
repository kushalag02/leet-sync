class Solution {
public:
    int maxDistance(vector<vector<int>>& A) {
        int n = A.size();

        int mini = A[0][0];
        int maxi = A[0][A[0].size() - 1];
        int ans = 0;

        for (int i = 1; i < n; i++) {
            ans = max(ans, abs(A[i][A[i].size() - 1] - mini));
            ans = max(ans, abs(maxi - A[i][0]));

            mini = min(mini, A[i][0]);
            maxi = max(maxi, A[i][A[i].size() - 1]);
        }

        return ans;
    }
};
