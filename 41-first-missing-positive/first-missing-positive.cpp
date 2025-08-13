class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        // for (int i = 0; i < n; i++) {
        //     if (A[i] <= 0 || A[i] > n) {
        //         A[i] = n + 1;
        //     }
        // }
        for (int i : A) {
            while (i >= 1 && i <= n && A[i - 1] != i) {
                swap(i, A[i - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};
