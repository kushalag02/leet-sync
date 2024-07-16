class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int maxi = INT_MIN;
        subtreeSum(root, maxi);
        return maxi;
    }
    
    int subtreeSum(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0;
        }

        int left = max(0, subtreeSum(root->left, maxi));
        int right = max(0, subtreeSum(root->right, maxi));

        int currentMax = root->val + left + right;
        maxi = max(maxi, currentMax);

        return root->val + max(left, right);
    }
};
