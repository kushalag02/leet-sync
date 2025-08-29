class Solution {
public:
    string resultingString(string s) {
        int n = s.length();
        string ans = "";
        for (char c : s) {
            if (ans.empty() == false) {
                int diff = abs(ans.back() - c);
                if (diff == 1 || diff == 25) {
                    ans.pop_back();
                    continue;
                }
            }
            ans += c;
        }
        return ans;
    }
};