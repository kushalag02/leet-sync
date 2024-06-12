class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ((2 * i) + 2 >= n)
                continue;
            int left = cost[(2 * i) + 1];
            int right = cost[(2 * i) + 2];
            ans += abs(left - right);
            cost[i] += max(left, right);
        }
        return ans;
    }
};