class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        // unordered_map<char, int> mp(26, 0);

        for (int i = 0; i < word.length();) {
            int countword = 0;
            char c = word[i];
            while (i < word.length() && word[i] == c && countword < 9) {
                countword++;
                i++;
                // if (countword >= 9) {
                //     countword = 0;
                // }
            }
            ans += to_string(countword) + c;
        }
        return ans;
    }
};