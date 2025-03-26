class Solution {
public:
    long long dividePlayers(vector<int>& A) {
        sort(begin(A), end(A));
        int n = A.size();
        long long sum = A[0] + A[n - 1];
        long long prod = 0;
        for (int i = 0; i < n / 2; i++) {
            if (A[i] + A[n - i - 1] != sum) {
                return -1;
            }
        }
        for (int i = 0; i < n / 2; i++) {
            prod += (A[i] * A[n - i - 1]);
        }
        return prod;
    }
};