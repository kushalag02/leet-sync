class Solution {
public:
    int count(vector<int>& nums, int maxi) {
        int n = nums.size();
        int part = 1;
        int tempSum = 0;
        for (int i = 0; i < n; i++) {
            if (tempSum + nums[i] <= maxi) {
                tempSum += nums[i];
            } else {
                part++;
                tempSum = nums[i];
            }
        }
        return part;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi = 0;
        int mini = INT_MIN;
        for (int i : nums) {
            mini = max(mini, i);
            maxi += i;
        }

        while (mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;
            int part = count(nums, mid);
            if (part > k) {
                mini = mid + 1;
            } else {
                maxi = mid - 1;
            }
        }
        return mini;
    }
};