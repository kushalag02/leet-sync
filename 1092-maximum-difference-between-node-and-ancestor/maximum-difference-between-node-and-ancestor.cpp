/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int mini, int maxi, int& maxDiff) {
        if (root == NULL)
            return;

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        maxDiff = max(maxDiff, maxi - mini);

        solve(root->left, mini, maxi, maxDiff);
        solve(root->right, mini, maxi, maxDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int maxDiff = 0;
        solve(root, root->val, root->val, maxDiff);
        return maxDiff;
    }
};