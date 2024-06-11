class Solution {
public:
    int solve(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vp(32);
        for (int i : nums) {
            int cnt = solve(i);
            vp[cnt].push_back(i);
        }

        vector<int> result;
        for (int i = 0; i < vp.size(); i++) {
            if (vp[i].empty() == false) {
                sort(vp[i].begin(), vp[i].end());
                for (int num : vp[i]) {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};
