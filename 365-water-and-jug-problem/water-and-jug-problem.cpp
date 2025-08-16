class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x % 2 == 0 && y % 2 == 0 &&
            target % 2 == 1) // dono even and target odd
            return false;
        if (x + y == target)
            return true;
        if (x + y < target || target == 0)
            return false;
        if (target % __gcd(x, y) == 0)
            return true;
        return false;
        // rest logic need to find.
    }
};