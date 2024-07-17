class Solution {
public:
    TreeNode* solve(TreeNode* root, vector<bool>& vis,
                    vector<TreeNode*>& forest) {
        if (root == NULL)
            return NULL;

        root->left = solve(root->left, vis, forest);
        root->right = solve(root->right, vis, forest);

        if (vis[root->val] == true) {
            if (root->left != NULL)
                forest.push_back(root->left);
            if (root->right != NULL)
                forest.push_back(root->right);
            return NULL;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& A) {
        vector<bool> vis(1001, false);
        for (int i : A) {
            vis[i] = true;
        }

        if (root == NULL) {
            return {};
        }

        vector<TreeNode*> forest;
        if (!vis[root->val]) {
            forest.push_back(root);
        }
        solve(root, vis, forest);
        return forest;
    }
};