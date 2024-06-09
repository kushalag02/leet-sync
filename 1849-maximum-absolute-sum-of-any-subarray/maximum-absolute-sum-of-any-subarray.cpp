class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int ans = 0;
        for (int i : nums) {
            sum += i;
            maxi = max(maxi, sum);
            sum = max(sum, 0);
        }
        sum = 0;
        for (int i : nums) {
            sum += i;
            mini = min(mini, sum);
            sum = min(sum, 0);
        }
        return max(maxi, abs(mini));
    }
};