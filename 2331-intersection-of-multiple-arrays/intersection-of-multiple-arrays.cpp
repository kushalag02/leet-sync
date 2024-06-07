class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            vector<int> temp;
            vector<int> curr = nums[i];
            sort(curr.begin(), curr.end());
            for (int num : result) {
                auto it = find(curr.begin(), curr.end(), num);
                if (it != curr.end()) {
                    temp.push_back(num);
                    curr.erase(it);
                }
            }
            result = temp;
        }
        sort(result.begin(), result.end());
        return result;
    }
};