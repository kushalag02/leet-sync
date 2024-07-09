class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& A) {
        double ans = 0;
        int time = 0;
        int n = A.size();
        // vector<int> time(n);
        // time[0] = A[0][1] - A[0][0];

        for (int i = 0; i < n; i++) {
            time = max(time, A[i][0]) + A[i][1];
            ans += time - A[i][0];
        }
        double sum = 0;
        sum = ans / n;
        return sum;
    }
};