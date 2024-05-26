class Solution {
public:
    int depth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    int traverse(TreeNode* root, int height, int depth) {
        if (root == NULL)
            return 0;
        if (height == depth)
            return root->val;
        return traverse(root->left, height + 1, depth) +
               traverse(root->right, height + 1, depth);
    }
    int deepestLeavesSum(TreeNode* root) {
        int ans = depth(root);
        return traverse(root, 1, ans);
    }
};