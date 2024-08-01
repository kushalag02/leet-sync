class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (string s : details) {
            char age1 = s[11];
            char age2 = s[12];
            if (age1 > '6') {
                ans++;
            } else if (age1 == '6' && age2 > '0') {
                ans++;
            }
        }
        return ans;
    }
};
