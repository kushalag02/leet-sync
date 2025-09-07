class Solution {
public:
    bool isOnRightSide(vector<int>& nums, int idx) {
        if (idx % 2 == 0) {
            return nums[idx] != nums[idx + 1];
        } else {
            return nums[idx] != nums[idx - 1];
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        // int ans = 0;
        // for (int i : nums) {
        //     ans ^= i;
        // }
        // return ans;

        int left = -1;
        int right = nums.size();
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (isOnRightSide(nums, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return nums[right];
    }
};