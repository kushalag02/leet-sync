class Solution {
public:
    // void inorder(TreeNode* root, vector<int>& result) {
    //     if (root == NULL)
    //         return;
    //     inorder(root->left, result);
    //     result.push_back(root->val);
    //     inorder(root->right, result);
    // }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL)
            return root;
        if (root->val > high)
            return trimBST(root->left, low, high);
        if (root->val < low)
            return trimBST(root->right, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};