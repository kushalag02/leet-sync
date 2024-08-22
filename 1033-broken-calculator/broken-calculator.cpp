class Solution {
public:
    int brokenCalc(int n, int target) {
        int ans = 0;
        if (n - 1 == target)
            return 1;
        if (n >= target) {
            return n - target;
        }
        if (target % 2 == 1) {
            return 1 + brokenCalc(n, target + 1);
        }
        return 1 + brokenCalc(n, target / 2);
    }
};