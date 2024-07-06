class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (A[i] == A[i + 2] && A[i] != A[i + 1]) {
                ans++;
            }
        }
        if (A[n - 2] == A[0] && A[0] != A[n - 1]) {
            ans++;
        }
        if (A[n - 1] == A[1] && A[1] != A[0]) {
            ans++;
        }
        return ans;
    }
};