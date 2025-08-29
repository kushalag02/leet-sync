class Solution {
public:
    long long flowerGame(int n, int m) {
        // count total cases and half of them will be odd and half even
        // Aloce can wil if odd is there

        if (n == 1 && m == 1)
            return 0;

        long long ans = (long long)n * m / 2;
        return ans;
    }
};