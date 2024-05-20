class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if (n < 3)
            return 0;

        vector<int> up(n, 0), down(n, 0);
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (A[i + 1] > A[i]) {
                up[i + 1] = up[i] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i + 1]) {
                down[i] = down[i + 1] + 1;
            }
        }
        // 0 0 1 2 0 0 1
        // 0 0 0 2 1 0 0

        for (int i = 0; i < n - 1; i++) {
            if (up[i] > 0 && down[i] > 0) {
                count = max(count, up[i] + down[i] + 1);
            }
        }

        return count;
    }
};
