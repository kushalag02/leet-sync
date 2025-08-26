class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& A) {
        double maxi = 0;
        int ans = 0;
        int n = A.size();
        
        for (int i = 0; i < n; i++) {
            int len = A[i][0];
            int bre = A[i][1];

            double diag = sqrt(1.0 * len * len + 1.0 * bre * bre);
            if (diag > maxi) {
                maxi = diag;
                ans = len * bre;
            } else if (diag == maxi) {
                ans = max(ans, len * bre);
            } else {
                continue;
            }
        }
        return ans;
    }
};