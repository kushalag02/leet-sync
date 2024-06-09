class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane`s Algo.
        int sum = 0;
        int maxi = INT_MIN;
        for (int i : nums) {
            sum += i;
            maxi = max(maxi, sum);
            sum = max(sum, 0);
        }
        return maxi;
    }
};