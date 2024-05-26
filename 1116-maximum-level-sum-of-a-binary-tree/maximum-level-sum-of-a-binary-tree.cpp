class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        vector<int> result;
        levelOrder(root, result);
        int maxi = INT_MIN;
        int level = 0;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] > maxi) {
                maxi = result[i];
                level = i + 1;
            }
        }
        return level;
    }
    void levelOrder(TreeNode* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (que.empty() == false) {
            int size = que.size();
            int sum = 0;
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
            result.push_back(sum);
        }
    }
};