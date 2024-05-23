class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int maxi = max(max(a, b), c);
        int mini = min(min(a, b), c);
        int left = a + b + c - maxi - mini;
        if (mini + left < maxi)
            return mini + left;
        return (a + b + c) / 2;
    }
};