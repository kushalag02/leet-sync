class Solution {
public:
    int numTeams(vector<int>& A) {
        int n = A.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if ((A[i] < A[j] && A[j] < A[k]) ||
                        (A[i] > A[j] && A[j] > A[k])) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
