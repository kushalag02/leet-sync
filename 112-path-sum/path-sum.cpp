class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        int sum = 0;
        solve(root, ans, targetSum);
        return ans;
    }

    void solve(TreeNode* root, bool& ans, int targetSum) {
        if (!root)
            return;

        if (ans)
            return;

        if (!root->left && !root->right && targetSum == root->val) {
            ans = true;
        } else {
            solve(root->left, ans, targetSum - root->val);
            solve(root->right, ans, targetSum - root->val);
        }
    }
};