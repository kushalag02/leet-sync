class Solution {
public:
    int heightChecker(vector<int>& A) {
        vector<int> B = A;
        sort(A.begin(), A.end());
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i])
                count++;
        }
        return count;
    }
};