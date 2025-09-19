class Solution {
public:
    void solve(int i, int n, int k, vector<int>& A,
               vector<vector<int>>& ans) {
        if (A.size() == k) {
            ans.push_back(A);
            return;
        }

        if (i > n) {
            return;
        }

        // Take i
        A.push_back(i);
        solve(i + 1, n, k, A, ans);

        // Not take i
        A.pop_back();
        solve(i + 1, n, k, A, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> A;
        solve(1, n, k, A, ans);
        return ans;
    }
};
