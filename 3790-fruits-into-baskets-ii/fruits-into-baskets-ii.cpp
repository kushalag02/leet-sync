class Solution {
public:
    int numOfUnplacedFruits(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> check(n, 0);

        int count = 0;

        for (int i = 0; i < n; i++) {
            int flag = 0;
            for (int j = 0; j < n; j++) {
                if (check[j] == 0 && B[j] >= A[i]) {
                    check[j] = 1;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                count++;
            }
        }
        return count;
    }
};
