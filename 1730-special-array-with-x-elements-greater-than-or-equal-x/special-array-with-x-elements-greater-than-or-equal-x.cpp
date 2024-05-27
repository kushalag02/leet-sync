class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return -1;
        if (n == 1 && nums[0] == 0)
            return -1;
        if (n == 1 && nums[0] != 0)
            return 1;
        if (n == 2) {
            if (nums[0] != nums[1])
                return 2;
            else
                return -1;
        }
        sort(begin(nums), end(nums));
        for (int i = 0; i <= n; i++) {
            int countVal = count(nums, i);
            if (countVal == i) {
                return i;
            }
        }
        return -1;
    }
    int count(vector<int>& nums, int val) {
        int ans = 0;
        for (int num : nums) {
            if (num >= val)
                ans++;
        }
        return ans;
    }
};