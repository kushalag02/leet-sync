class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n != m)
            return false;
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for (char c : word1)
            mp1[c - 'a']++;
        for (char c : word2)
            mp2[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (mp2[i] != 0 && mp1[i] == 0)
                return false;
            if (mp1[i] != 0 && mp2[i] == 0)
                return false;
        }
        sort(begin(mp1), end(mp1));
        sort(begin(mp2), end(mp2));
        return mp1 == mp2;
    }
};