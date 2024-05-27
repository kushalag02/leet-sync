class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        levelOrder(root, result);
        return result;
    }
    void levelOrder(TreeNode* root, vector<int>& result) {
        if (root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            result.push_back(level[size - 1]);
        }
    }
};