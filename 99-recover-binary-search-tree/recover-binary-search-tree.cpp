class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (root == NULL)
            return;

        vector<int> result;
        inorder(root, result);

        int first = -1, second = -1;
        for (int i = 0; i < result.size() - 1; i++) {
            if (result[i + 1] < result[i]) {
                if (first == -1) {
                    first = i;
                    second = i + 1;
                } else {
                    second = i + 1;
                    break;
                }
            }
        }

        recover(root, result[first], result[second]);
    }
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == NULL)
            return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    void recover(TreeNode* root, int first, int second) {
        if (root == NULL)
            return;

        if (root->val == first) {
            root->val = second;
        } else if (root->val == second) {
            root->val = first;
        }

        recover(root->left, first, second);
        recover(root->right, first, second);
    }
};