class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int count = 0;
        long long int prod = 1;
        int j = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            
            while (prod >= k) {
                prod /= nums[j];
                j++;
            }
            
            count += (i - j + 1);
        }
        
        return count;
    }
};
