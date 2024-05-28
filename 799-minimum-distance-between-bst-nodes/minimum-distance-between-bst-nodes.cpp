class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        int diff = INT_MAX;
        int mini = INT_MAX;
        for (int i = 0; i < result.size() - 1; i++) {
            diff = result[i + 1] - result[i];
            mini = min(mini, diff);
        }
        return mini;
    }
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == NULL)
            return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};