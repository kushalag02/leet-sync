class Solution {
public:
    int countPermutations(vector<int>& A) {
        const int mod = 1000000007;
        int n = A.size();
        long long ans = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] <= A[0]) {
                return 0;
            }
            // For factorial
            ans *= i;
            ans %= mod;
        }
        return (int)ans;
    }
};