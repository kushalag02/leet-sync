class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
    }
};