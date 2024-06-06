class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int maxi = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            maxi = max(maxi, it->second);
        }
        unordered_set<char> temp;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second == maxi) {
                temp.insert(it->first);
            }
        }
        string result;
        unordered_set<char> vis;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (temp.count(s[i]) == 1 && vis.count(s[i]) != 1) {
                result += s[i];
                vis.insert(s[i]);
            }
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
