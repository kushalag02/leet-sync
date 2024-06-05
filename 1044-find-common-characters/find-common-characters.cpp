class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        for (char c : words[0]) {
            result.push_back(string(1, c));
        }
        for (int i = 1; i < words.size(); i++) {
            vector<string> temp;
            string curr = words[i];
            sort(curr.begin(), curr.end());
            for (string s : result) {
                char c = s[0];
                auto it = find(curr.begin(), curr.end(), c);
                if (it != curr.end()) {
                    temp.push_back(s);
                    curr.erase(it);
                }
            }
            result = temp;
        }

        return result;
    }
};