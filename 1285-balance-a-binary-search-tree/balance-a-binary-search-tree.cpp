
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == NULL)
            return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
    TreeNode* makeTree(vector<int>& result, int start, int end) {
        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(result[mid]);
        root->left = makeTree(result, start, mid - 1);
        root->right = makeTree(result, mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // AVL Tree
        if (root == NULL)
            return NULL;
        vector<int> result;
        inorder(root, result);
        return makeTree(result, 0, result.size() - 1);
    }
};