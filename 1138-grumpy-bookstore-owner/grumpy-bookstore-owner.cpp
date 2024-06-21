class Solution {
public:
    int maxSatisfied(vector<int>& B, vector<int>& A, int minutes) {
        int res = 0;
        int curr = 0;
        for (int i = 0; i < B.size(); i++) {
            if (A[i] == 0) {
                res += B[i];
            }
        }

        for (int i = 0; i < minutes; i++) {
            if (A[i] == 1) {
                curr += B[i];
            }
        }

        int maxi = curr;
        for (int i = minutes; i < B.size(); i++) {
            if (A[i - minutes])
                curr -= B[i - minutes];
            if (A[i] == 1)
                curr += B[i];
            maxi = max(maxi, curr);
        }

        return res + maxi;
    }
};