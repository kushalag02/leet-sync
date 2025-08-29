class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        // Bit masking 

        int ans = 0;
        int prev = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while ((prev & nums[i]) != 0) {
                prev ^= nums[j];
                // Move the left pointer till the condition works
                j++;
            }

            prev |= nums[i]; // Stores the set bits (need to take and)
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};