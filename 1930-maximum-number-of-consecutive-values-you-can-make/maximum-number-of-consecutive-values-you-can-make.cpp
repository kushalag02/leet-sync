class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n = coins.size();
        sort(begin(coins), end(coins));
        // map<int, int> mp;
        // for (int i : coins) {
        //     mp[i]++;
        // }
        int ans = 1;
        for (int i : coins) {
            if (i > ans)
                break;
            ans += i;
        }
        return ans;
    }
};