class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        int ct = 0;
        for (auto& pt : mp) {
            if (pt.second % 2 != 0) {
                ct++;
            }
        }

        return ct <= k && s.size() >= k;
    }
};