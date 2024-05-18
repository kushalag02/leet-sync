class Solution {
public:
    int ans = 0;
    int distributeCoins(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL && root->val != 1)
            return -1;
        solve(root);
        return ans;
    }
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);

        ans += abs(left) + abs(right);
        return left + right + root->val - 1;
    }
};