class Solution {
public:
    int SumXOR(const vector<int>& subset) {
        int xor_sum = 0;
        for (int num : subset) {
            xor_sum ^= num;
        }
        return xor_sum;
    }
    void subSet(vector<int>& nums, vector<int>& current, int index,
                int& ans) {
        if (index == nums.size()) {
            ans += SumXOR(current);
            return;
        }

        current.push_back(nums[index]);
        subSet(nums, current, index + 1, ans);
        current.pop_back();
        subSet(nums, current, index + 1, ans);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> current;
        int ans = 0;
        subSet(nums, current, 0, ans);
        return ans;
    }
};
