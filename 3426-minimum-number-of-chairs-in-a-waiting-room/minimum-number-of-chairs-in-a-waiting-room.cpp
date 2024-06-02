class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int enter = 0;

        for (char ch : s) {
            if (ch == 'E') {
                enter++;
                ans = max(ans, enter);
            } else if (ch == 'L') {
                enter--;
            }
        }

        return ans;
    }
};
