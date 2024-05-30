class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        
        if (root == NULL) {
            return newNode;
        }
        
        TreeNode* current = root;
        
        while (true) {
            if (val > current->val) {
                if (current->right == NULL) {
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            } else { // val < current->val
                if (current->left == NULL) {
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            }
        }
        
        return root;
    }
};
