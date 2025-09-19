class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> ans(2);
        // **++*
        vector<int> A;
        A.push_back(a);
        A.push_back(b);
        A.push_back(c);
        sort(begin(A), end(A));

        int mini = 0;
        int maxi = 0;

        int d1 = A[1] - A[0];
        int d2 = A[2] - A[1];
        maxi = A[2] - A[0] - 2;

        if (d1 == d2 && d1 == 1) {
            mini = 0;
        } else if (d1 == 2 || d2 == 2)
            mini = 1;
        else if (d1 > 2 && d2 == 1) {
            mini = 1;
        } else if (d1 == 1 && d2 > 2) {
            mini = 1;
        } else {
            mini = 2;
        }
        ans[0] = mini;
        ans[1] = maxi;
        return ans;
    }
};