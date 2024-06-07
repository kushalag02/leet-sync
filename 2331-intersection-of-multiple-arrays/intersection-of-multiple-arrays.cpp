class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> A(1001, 0);

        for (int i = 0; i < n; i++) {
            for (auto it : nums[i]) {
                A[it]++;
            }
        }
        vector<int> count;
        for (int i = 1; i <= 1000; i++) {
            if (A[i] == n) {
                count.push_back(i);
            }
        }

        return count;
    }
};