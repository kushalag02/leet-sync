class Solution {
public:
    // int maxDepth(TreeNode* node) {
    //     if (node == NULL) {
    //         return 0;
    //     }
    //     int lDepth = maxDepth(node->left);
    //     int rDepth = maxDepth(node->right);

    //     return max(lDepth, rDepth) + 1;
    // }
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) {
            return false;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            bool flagX = false;
            bool flagY = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val == x) {
                    flagX = true;
                }
                if (node->val == y) {
                    flagY = true;
                }

                if (node->left && node->right) {
                    if ((node->left->val == x && node->right->val == y) ||
                        (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            if (flagX && flagY)
                return true;
            if (flagX || flagY)
                return false;
        }

        return false;
    }
};