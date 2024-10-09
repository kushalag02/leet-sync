class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s == " ") {
            return 0;
        }
        int c = 0;
        int temp = 0;
        for (char ch : s) {
            if (ch == '(') {
                c++;
            } else {
                if (c > 0) {
                    c--;
                } else {
                    temp++;
                }
            }
        }
        return c + temp;
    }
};