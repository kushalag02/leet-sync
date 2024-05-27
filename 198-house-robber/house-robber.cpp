class Solution {
public:
    int rob(vector<int>& nums) {
        // Pehla question DP ka jo begar tuitorial solve kiya
        int n = nums.size();
        int prev1 = 0;
        int prev2 = 0;
        for (int num : nums) {
            int curr = prev1;
            prev1 = max(prev1, prev2 + num);
            prev2 = curr;
        }
        return prev1;
    }
};