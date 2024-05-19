class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore Voting Algo.
        int n = nums.size();
        int count = 0;
        int majorE = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0)
                majorE = nums[i];
            if (nums[i] != majorE)
                count--;

            if (nums[i] == majorE)
                count++;
        }
        int testCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == majorE)
                testCount++;
        }
        return majorE;
    }
};