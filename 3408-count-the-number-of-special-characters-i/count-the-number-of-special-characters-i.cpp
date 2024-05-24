class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        for (char c : word) {
            mp[c]++;
        }

        int count = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (mp.count(c) && mp.count(toupper(c))) {
                count++;
            }
        }

        return count;
    }
};