class Solution {
public:
    int bitss(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n);
        for (int i = 0; i < n; i++) {
            int temp = bitss(nums[i]);
            check[i] = temp;
        }
        vector<int> ma;
        vector<int> mi;
        int maxi = nums[0];
        int mini = nums[0];
        int temp_bit = check[0];
        for (int i = 1; i < n; i++) {
            if (check[i] == check[i - 1]) {
                maxi = max(maxi, nums[i]);
                mini = min(mini, nums[i]);
            } else {
                ma.push_back(maxi);
                mi.push_back(mini);
                maxi = nums[i];
                mini = nums[i];
            }
        }
        ma.push_back(maxi);
        mi.push_back(mini);
        for (int i = 1; i < ma.size(); i++) {
            if (ma[i] <= ma[i - 1])
                return false;
            if (mi[i] <= mi[i - 1])
                return false;
            if (i > 0) {
                if (mi[i] < ma[i - 1])
                    return false;
            }
        }

        return true;
    }
};