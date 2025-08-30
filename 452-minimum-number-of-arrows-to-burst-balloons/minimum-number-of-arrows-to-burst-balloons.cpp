bool compare(vector<int>& A, vector<int>& B) { return A[1] < B[1]; }
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& A) {
        sort(begin(A), end(A), compare);
        int ans = 1;
        int win = A[0][1];
        int n = A.size();
        for (int i = 1; i < n; i++) {
            if (A[i][0] > win) {
                ans++;
                win = A[i][1];
            }
        }
        return ans;
    }
};