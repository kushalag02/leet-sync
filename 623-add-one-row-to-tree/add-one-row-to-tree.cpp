class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        queue<TreeNode*> q;
        q.push(root);

        int height = 1;
        while (!q.empty()) {
            int size = q.size();

            if (height == depth - 1) {
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();

                    TreeNode* Lsubtree = node->left;
                    TreeNode* Rsubtree = node->right;

                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);
                    node->left->left = Lsubtree;
                    node->right->right = Rsubtree;
                }
                break;
            } else {
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();

                    if (node->left != NULL)
                        q.push(node->left);
                    if (node->right != NULL)
                        q.push(node->right);
                }
            }
            height++;
        }
        return root;
    }
};