class Solution {
public:
    TreeNode* solve(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(A[i++]);
        root->left = solve(A, i, root->val);
        root->right = solve(A, i, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return solve(A, i, INT_MAX);
    }
};
