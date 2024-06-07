class Solution {
public:
    long long maximumHappinessSum(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int n = A.size();
        long long sum = 0;
        int i = 1;
        while (k--) {
            long long last = A[n - i] - (i - 1);
            if (last > 0)
                sum += last;
            i++;
        }
        return sum;

        // int maxi = *max_element(begin(A), end(A));
        // sum += maxi;
        // for (int i = 0; i < A.size(); i++) {
        //     if (A[i] == maxi) {
        //         A[i] = 0;
        //         maxi = -1;
        //     } else
        //         A[i]--;
        //     if (A[i] < 0)
        //         A[i] = 0;
        // }

        return sum;
    }
};