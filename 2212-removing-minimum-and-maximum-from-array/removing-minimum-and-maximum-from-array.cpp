class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int n = A.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        int maxIdx = -1;
        int minIdx = -1;

        for (int i = 0; i < n; i++) {
            if (A[i] > maxi) {
                maxi = A[i];
                maxIdx = i;
            }
            if (A[i] < mini) {
                mini = A[i];
                minIdx = i;
            }
        }

        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        int w1 = maxIdx + 1;
        int w2 = n - minIdx;
        int w3 = (minIdx + 1) + (n - maxIdx);

        return min({w1, w2, w3});
    }
};