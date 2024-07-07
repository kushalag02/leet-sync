class Solution {
public:
    int maxBottlesDrunk(int m, int n) {
        int empty = 0;
        int ans = 0;
        while (m > 0 || empty >= n) {
            if (empty >= n) {
                empty -= n;
                m++;
                n++;
            } else {
                empty += m;
                ans += m;
                m = 0;
            }
        }
        return ans;
    }
};