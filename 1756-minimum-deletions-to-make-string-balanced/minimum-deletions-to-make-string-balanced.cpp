class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int countA = 0;
        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                countA++;
            } else {
                ans = min(ans + 1, countA);
            }
        }
        return ans;
    }
};