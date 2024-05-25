class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> ans(n);
        int mid = (n + 1) / 2 - 1;
        int right = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                ans[i] = nums[right];
                right--;
            } else {
                ans[i] = nums[mid];
                mid--;
            }
        }
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};