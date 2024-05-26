class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        levelOrder(root, result);
        return result;
    }
    void levelOrder(TreeNode* root, vector<double>& result) {
        if (root == NULL) {
            return;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (que.empty() == false) {
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
            result.push_back(sum / size);
        }
    }
};