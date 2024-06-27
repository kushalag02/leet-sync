class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
                if (count == k) {
                    ans = i;
                    break;
                }
            }
        }
        return ans;
    }
};