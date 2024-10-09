class Solution {
public:
    int minSwaps(string s) {
        if (s == " ") {
            return 0;
        }
        int maxi = 0;
        int c = 0;
        for (char ch : s) {
            if (ch == '[') {
                c++;
            } else {
                c--;
            }
            maxi = min(maxi, c);
        }
        return (-maxi + 1) / 2;
    }
};