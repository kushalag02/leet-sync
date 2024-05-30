class Solution {
public:
    int sumNumbers(TreeNode* root) { return solve(root, 0); }
    int solve(TreeNode* node, int sum) {
        if (node == NULL) {
            return 0;
        }
        sum = sum * 10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            return sum;
        }
        return solve(node->left, sum) + solve(node->right, sum);
    }
};