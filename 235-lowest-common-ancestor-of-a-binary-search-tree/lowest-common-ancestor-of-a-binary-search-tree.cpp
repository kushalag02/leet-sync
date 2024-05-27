class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Best method
        int mini = min(p->val, q->val);
        int maxi = max(p->val, q->val);
        while (root != NULL) {
            if (root->val > maxi) {
                root = root->left;
            } else if (root->val < mini) {
                root = root->right;
            } else {
                return root;
            }
        }
        return NULL;
    }
};