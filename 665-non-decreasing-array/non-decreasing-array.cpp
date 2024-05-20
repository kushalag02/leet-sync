class Solution {
public:
    bool checkPossibility(vector<int>& A) {
        int n = A.size();
        int count = 0;

        for (int i = 1; i < n; i++) {
            if (A[i] < A[i - 1]) {
                count++;
                if (count > 1) {
                    return false;
                }
                if (i != 1 && A[i] < A[i - 2]) {
                    A[i] = A[i - 1];
                } else {
                    A[i - 1] = A[i];
                }
            }
        }

        return true;
    }
};
