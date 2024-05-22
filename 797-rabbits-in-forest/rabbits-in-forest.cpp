class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int color : answers) {
            if (color == 0) {
                ans++;
                continue;
            }
            if (mp[color] == 0) {
                mp[color] = color;
                ans++;
                ans += color;
            } else {
                mp[color]--;
            }
        }
        return ans;
    }
};