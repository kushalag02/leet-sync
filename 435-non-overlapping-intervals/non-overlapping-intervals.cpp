bool compare(vector<int>& A, vector<int>& B) { return A[1] < B[1]; }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& A) {
        int n = A.size();
        int ans = 0;

        sort(begin(A), end(A), compare);

        int prev = A[0][1];

        for (int i = 1; i < n; i++) {
            if (A[i][0] < prev)
                ans++;
            else
                prev = A[i][1];
        }
        return ans;
    }
};