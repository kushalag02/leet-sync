#include <vector>
#include <string>

class Solution {
public:
    int countHomogenous(std::string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        if (n == 0)
            return 0;

        vector<int> A(n, 0);
        A[0] = 1;
        int ans = 1;

        for (int i = 0; i < n-1; i++) {
            if (s[i+1] == s[i]) {
                A[i+1] = (A[i] + 1) % mod;
            } else {
                A[i+1] = 1;
            }
            ans = (ans + A[i+1]) % mod;
        }
        return ans;
    }
};
