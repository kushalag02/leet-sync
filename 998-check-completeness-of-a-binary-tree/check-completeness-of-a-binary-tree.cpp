class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left != NULL) {
                if (flag == true)
                    return false;
                q.push(current->left);
            } else {
                flag = true;
            }
            if (current->right != NULL) {
                if (flag)
                    return false;
                q.push(current->right);
            } else {
                flag = true;
            }
        }

        return true;
    }
};