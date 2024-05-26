class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        traversal(root, result, 0);
        return result;
    }
    void traversal(TreeNode* root, vector<int>& result, int depth) {
        if (root == NULL) {
            return;
        }
        if (depth == result.size()) {
            result.push_back(root->val);
        } else {
            result[depth] = max(result[depth], root->val);
        }
        traversal(root->left, result, depth + 1);
        traversal(root->right, result, depth + 1);
    }
};