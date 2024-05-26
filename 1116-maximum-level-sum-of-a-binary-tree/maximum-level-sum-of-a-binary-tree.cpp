class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        vector<int> sums;
        levelOrder(root, sums);
        int maxSum = INT_MIN;
        int maxLevel = 0;
        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] > maxSum) {
                maxSum = sums[i];
                maxLevel = i + 1;
            }
        }
        return maxLevel;
    }

    void levelOrder(TreeNode* root, vector<int>& sums) {
        if (root == NULL)
            return;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while (!que.empty()) {
            ++level;
            int size = que.size();
            int levelSum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                levelSum += node->val;
                if (node->left != NULL)
                    que.push(node->left);
                if (node->right != NULL)
                    que.push(node->right);
            }
            sums.push_back(levelSum);
        }
    }
};
