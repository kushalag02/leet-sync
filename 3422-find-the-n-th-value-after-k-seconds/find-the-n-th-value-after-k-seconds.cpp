class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int MOD = 1e9 + 7;
        vector<int> A(n, 1);

        while (k--) {
            vector<int> temp(n, 0);
            temp[0] = A[0];
            for (int i = 0; i < n - 1; i++) {
                temp[i + 1] = (temp[i] + A[i + 1]) % MOD;
            }
            A = temp;
        }

        return A[n - 1];
    }
};
