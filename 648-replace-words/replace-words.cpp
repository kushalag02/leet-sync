class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        sort(dictionary.begin(), dictionary.end());
        vector<string> ans;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                ans.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }
        ans.push_back(temp);
        for (int i = 0; i < ans.size(); i++) {
            string word = ans[i];
            for (string root : dictionary) {
                if (word.substr(0, root.size()) == root) {
                    ans[i] = root;
                    break;
                }
            }
        }
        string final = "";
        for (auto i : ans) {
            final += i + " ";
        }
        final.pop_back();
        return final;
    }
};
