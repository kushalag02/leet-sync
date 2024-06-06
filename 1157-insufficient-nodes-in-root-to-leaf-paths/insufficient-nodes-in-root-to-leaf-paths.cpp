class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root->left == root->right) {
            if (root->val >= limit)
                return root;
            else
                return NULL;
        }
        if (root->left != NULL)
            root->left = sufficientSubset(root->left, limit - root->val);
        if (root->right != NULL)
            root->right = sufficientSubset(root->right, limit - root->val);
        if (root->left == root->right)
            return NULL;
        else
            return root;
    }
};