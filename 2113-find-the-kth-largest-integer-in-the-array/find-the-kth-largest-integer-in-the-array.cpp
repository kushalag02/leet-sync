bool compare(string a, string b) {
    if (a.size() == b.size()) {
        if (a < b)
            return true;
        else
            return false;
    } else {
        if (a.size() < b.size())
            return true;
        else
            return false;
    }
}

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        return nums[nums.size() - k];
    }
};
