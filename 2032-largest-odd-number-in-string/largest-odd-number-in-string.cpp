class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int idx = -1; 
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            return "";
        }
        return num.substr(0, idx + 1);
    }
};
