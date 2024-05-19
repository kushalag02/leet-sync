class Solution {
public:
    bool solve(TreeNode* root, int val) {
        if (root == NULL)
            return true;
        if (root->val != val)
            return false;
        return solve(root->left, val) && solve(root->right, val);
    }
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL)
            return true;
        return solve(root, root->val);
    }
};