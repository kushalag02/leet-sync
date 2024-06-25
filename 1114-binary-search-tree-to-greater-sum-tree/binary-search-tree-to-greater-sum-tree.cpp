class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
    void solve(TreeNode* root, vector<int>& result, int& idx) {
        if (root == NULL)
            return;
        solve(root->left, result, idx);
        root->val = result[idx];
        idx++;
        solve(root->right, result, idx);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        int n = result.size();
        for (int i = n - 2; i >= 0; i--) {
            result[i] += result[i + 1];
        }
        int idx = 0;
        solve(root, result, idx);
        return root;
    }
};