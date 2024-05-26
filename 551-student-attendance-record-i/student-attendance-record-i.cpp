class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        int absent = 0;
        for (char c : s) {
            if (c == 'A')
                absent++;
        }
        if (absent >= 2) {
            return false;
        }
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L') {
                return false;
            }
        }
        return true;
    }
};