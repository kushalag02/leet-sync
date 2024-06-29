class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int ans = 0;
        // for (int i : nums) {
        //     ans ^= i;
        // }
        // return ans;

        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();

        if (n == 1)
            return nums[0];

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[mid + 1] && mid < n - 1) {
                if ((right - mid) % 2 == 0) {
                    left = mid + 2;
                } else {
                    right = mid - 1;
                }
            } else if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if ((mid - left) % 2 == 0) {
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return -1;
    }
};