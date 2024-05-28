class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL)
            return root;

        queue<TreeNode*> que;
        que.push(root);
        int height = 0;

        while (!que.empty()) {
            int size = que.size();
            vector<TreeNode*> levelNodes;
            vector<int> levelValues;

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                levelNodes.push_back(node);
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }

            if (height % 2 == 1) {
                for (int i = 0; i < size / 2; i++) {
                    swap(levelNodes[i]->val, levelNodes[size - 1 - i]->val);
                }
            }

            height++;
        }
        return root;
    }
};
