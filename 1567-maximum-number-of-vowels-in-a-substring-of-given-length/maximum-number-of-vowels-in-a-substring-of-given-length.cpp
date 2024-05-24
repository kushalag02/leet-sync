class Solution {
public:
    bool test(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        } else
            return false;
    }
    int maxVowels(string s, int k) {
        if (k == 0)
            return 0;
        int n = s.length();
        int vowelCount = 0;
        for (int i = 0; i < k; i++) {
            if (test(s[i])) {
                vowelCount++;
            }
        }
        int ans = vowelCount;
        for (int i = k; i < n; i++) {
            if (test(s[i])) {
                vowelCount++;
            }
            if (test(s[i - k])) {
                vowelCount--;
            }
            ans = max(ans, vowelCount);
        }

        return ans;
    }
};