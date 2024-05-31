class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string temp = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else if (s[i] == ' ' && temp.empty() == false) {
                ans.push_back(temp);
                temp = "";
            }
        }

        if (temp.empty()==false) {
            ans.push_back(temp);
        }

        reverse(begin(ans), end(ans));

        string result = "";
        for (int i = 0; i < ans.size(); i++) {
            result += ans[i];
            if (i != ans.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};
