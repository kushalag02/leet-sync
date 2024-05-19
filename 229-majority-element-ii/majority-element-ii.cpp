class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Using Boyer-Moore algorithm
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (count1 == 0 && el2 != nums[i]) {
                el1 = nums[i];
                count1++;
            } else if (count2 == 0 && el1 != nums[i]) {
                el2 = nums[i];
                count2++;
            } else if (nums[i] == el1)
                count1++;
            else if (nums[i] == el2)
                count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1)
                count1++;
            if (nums[i] == el2)
                count2++;
        }
        vector<int> ans;
        if (count1 > n / 3)
            ans.push_back(el1);
        if (count2 > n / 3)
            ans.push_back(el2);
        return ans;
    }
};