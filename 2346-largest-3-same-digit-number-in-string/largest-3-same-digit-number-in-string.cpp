class Solution {
public:
    string largestGoodInteger(string A) {
        int n = A.length();
        string ans = "";
        for (int i = 0; i < n - 2; i++) {
            if (A[i + 1] == A[i] && A[i] == A[i + 2]) {
                char num = A[i];
                string test(3, num);
                ans = max(ans, test);
            }
        }
        return ans;
    }
};