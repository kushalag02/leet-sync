class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) {
                return false;
            }
            if (nums[i] % 2 == 1 && nums[i + 1] % 2 == 1) {
                return false;
            }
        }
        return true;
    }
};