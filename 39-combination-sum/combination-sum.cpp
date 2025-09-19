class Solution {
public:
    void solve(int i, vector<int>& A, int target, vector<int>& arr,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(arr);
            return;
        }
        if (i >= A.size() || target < 0) {
            return;
        }

        // Take
        arr.push_back(A[i]);
        solve(i, A, target - A[i], arr, ans);

        // Not take
        arr.pop_back();
        solve(i + 1, A, target, arr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(0, A, target, arr, ans);
        return ans;
    }
};
