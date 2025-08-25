class Solution {
public:
    int dfs(TreeNode* root, int maxi) {
        int ans = 0;
        if (root == NULL)
            return 0;

        if (root->val >= maxi) {
            ans = 1;
            maxi = root->val;
        }

        ans += dfs(root->left, maxi) + dfs(root->right, maxi);

        return ans;
    }
    int goodNodes(TreeNode* root) { return dfs(root, root->val); }
};