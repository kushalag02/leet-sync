class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == NULL)
            return;
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL)
            return 0;
        vector<int> result;
        inorder(root, result);
        int sum = 0;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] >= low && result[i] <= high) {
                sum += result[i];
            }
        }
        return sum;
    }
};