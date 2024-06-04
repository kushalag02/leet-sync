class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL)
            return 0;
        int maxi = 0;
        traverse(root, maxi);
        return maxi;
    }

    int traverse(TreeNode* node, int& maxi) {
        if (node == NULL)
            return 0;

        int leftLength = traverse(node->left, maxi);
        int rightLength = traverse(node->right, maxi);

        int leftPath = 0;
        int rightPath = 0;
        if (node->left != NULL && node->left->val == node->val)
            leftPath = leftLength + 1;

        if (node->right != NULL && node->right->val == node->val)
            rightPath = rightLength + 1;

        maxi = max(maxi, leftPath + rightPath);
        return max(leftPath, rightPath);
    }
};
