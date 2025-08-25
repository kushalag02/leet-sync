class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int n = A.size();
        int l = 0;
        int r = 0;
        int zero = 0;
        int ans = 0;
        // max length of windoe that has exactly one 0 is ans

        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                zero++;
            }

            while (zero > 1) {
                if (A[l] == 0) {
                    zero--;
                }
                l++;
            }

            ans = max(ans, i - l);
        }

        return ans;
    }
};
