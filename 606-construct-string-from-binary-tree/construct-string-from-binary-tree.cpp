class Solution {
public:
    void preorder(TreeNode* root, string& ans) {
        if (root == NULL)
            return;
        ans.append(to_string(root->val));

        if (root->left != NULL || root->right != NULL) {
            ans.append("(");
            if (root->left != NULL) {
                preorder(root->left, ans);
            }
            ans.append(")");
            
            if (root->right != NULL) {
                ans.append("(");
                preorder(root->right, ans);
                ans.append(")");
            }
        }
    }
    
    string tree2str(TreeNode* root) {
        if (root == NULL)
            return "";
        string ans = "";
        preorder(root, ans);
        return ans;
    }
};
