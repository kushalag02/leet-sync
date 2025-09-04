class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, ans, path, targetSum);
        return ans;
    }

    void solve(TreeNode* root, vector<vector<int>>& ans, vector<int>& path,
               int targetSum) {
        if (!root)
            return;

        path.push_back(root->val);

        if (!root->left && !root->right && targetSum == root->val) {
            ans.push_back(path);
        } else {
            solve(root->left, ans, path, targetSum - root->val);
            solve(root->right, ans, path, targetSum - root->val);
        }
        path.pop_back();
    }
};
