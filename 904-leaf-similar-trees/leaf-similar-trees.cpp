class Solution {
public:
    void findLeaf(TreeNode* root, vector<int>& leaf) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            leaf.push_back(root->val);
        }
        findLeaf(root->left, leaf);
        findLeaf(root->right, leaf);
    }
    vector<int> makeArray(TreeNode* root) {
        vector<int> leafNode;
        findLeaf(root, leafNode);
        return leafNode;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> A;
        vector<int> B;
        A = makeArray(root1);
        B = makeArray(root2);

        return A == B;
    }
};