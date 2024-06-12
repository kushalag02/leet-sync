class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(begin(nums), end(nums));
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }

        int index = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            while (it->second--) {
                nums[index++] = it->first;
            }
        }
    }
};