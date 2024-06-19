class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        return max(solve(s, k, 'T'), solve(s, k, 'F'));
    }
    int solve(string& s, int k, char ch) {
        int left = 0;
        int right = 0;
        int maxi = 0;
        int count = 0;
        int n = s.size();

        while (right < n) {
            if (s[right] != ch) {
                count++;
            }
            while (count > k) {
                if (s[left] != ch) {
                    count--;
                }
                left++;
            }
            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;
    }
};