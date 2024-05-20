class Solution {
public:
    int minOperations(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (A[i + 1] <= A[i]) {
                int increment = A[i] - A[i + 1] + 1;
                A[i + 1] += increment;
                ans += increment;
            }
        }
        return ans;
    }
};
