class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Bit Manipulation
        int n = nums.size();
        int majorE = 0;

        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;
            int bitCount = 0;
            for (int num : nums) {
                if ((num & bit) != 0)
                    bitCount++;
            }
            if (bitCount > n / 2)
                majorE |= bit;
        }
        return majorE;
    }
};