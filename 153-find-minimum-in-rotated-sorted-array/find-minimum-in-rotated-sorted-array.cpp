class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = -1;
        int right = nums.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[n - 1]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[right];
    }
};