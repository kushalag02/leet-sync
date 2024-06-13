class Solution {
public:
    int minMovesToSeat(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            ans += abs(A[i] - B[i]);
        }
        return ans;
    }
};