class Solution {
public:
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        solve(root);
        return sum;
    }
    void solve(TreeNode* root) {
        if (root == NULL)
            return;
        if (root->val % 2 == 0) {
            if (root->left != NULL && root->left->left != NULL)
                sum += root->left->left->val;
            if (root->left != NULL && root->left->right != NULL)
                sum += root->left->right->val;
            if (root->right != NULL && root->right->left != NULL)
                sum += root->right->left->val;
            if (root->right != NULL && root->right->right != NULL)
                sum += root->right->right->val;
        }
        solve(root->left);
        solve(root->right);
    }
};