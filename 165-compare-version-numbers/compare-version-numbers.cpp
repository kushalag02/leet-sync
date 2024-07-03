class Solution {
public:
    int compareVersion(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < s.size() || j < t.size()) {
            int num1 = 0, num2 = 0;
            while (i < s.size() && s[i] != '.') {
                num1 = num1 * 10 + (s[i] - '0');
                i++;
            }

            while (j < t.size() && t[j] != '.') {
                num2 = num2 * 10 + (t[j] - '0');
                j++;
            }

            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
            i++;
            j++;
        }

        return 0;
    }
};
