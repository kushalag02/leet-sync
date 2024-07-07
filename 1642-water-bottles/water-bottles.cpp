class Solution {
public:
    int numWaterBottles(int m, int n) {
        int ans = m;
        while (m >= n) {
            int rem = m % n;
            int div = m / n;
            ans += div;
            m = div + rem;
        }
        return ans;
    }
};