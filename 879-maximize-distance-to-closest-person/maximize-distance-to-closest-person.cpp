class Solution {
public:
    int maxDistToClosest(vector<int>& A) {
        int n = A.size();
        int maxDist = INT_MIN;
        int count = 0;
        int temp = 0;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (A[i] == 1) {
                idx = i;
                temp++;
            }
        }
        if (temp == 1) {
            return max(idx, n - idx - 1);
        }
        if (temp == n) {
            return 0;
        }
        int maxi = 0;
        int firstOne = -1;
        for (int i = 0; i < n; i++) {
            if (A[i] == 1) {
                if (firstOne == -1) {
                    maxi = max(maxi, i);
                } else {
                    maxi = max(maxi, (i - firstOne) / 2);
                }
                firstOne = i;
            }
        }
        maxi = max(maxi, n - 1 - firstOne);

        return maxi;
    }
};
