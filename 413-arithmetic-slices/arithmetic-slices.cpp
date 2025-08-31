class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int l = 0;
        int count = 0;
        int curr = 0;
        for (int i = 0; i < n - 2; i++) {
            if (A[i + 1] - A[i] == A[i + 2] - A[i + 1]) {
                curr++;
                count += curr;

            } else {
                curr = 0;
            }
        }
        return count;
    }
};