class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int freq = 0;
        for (char ch : s) {
            mp[ch]++;
            if (mp[ch] % 2 == 0)
                freq--;
            else
                freq++;
        }
        if (freq > 1)
            return s.length() - freq + 1;
        return s.length();
    }
};