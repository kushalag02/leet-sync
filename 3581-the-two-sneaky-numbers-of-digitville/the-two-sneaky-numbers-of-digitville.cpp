class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        // vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int idx = nums[i] % n;
            nums[idx] += n;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] / n >= 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
