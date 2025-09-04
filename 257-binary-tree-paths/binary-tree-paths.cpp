class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        solve(root, "", result);
        return result;
    }
    void solve(TreeNode* root, string path, vector<string>& result) {
        if (!root)
            return;

        if (path.empty())
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);

        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }
        solve(root->left, path, result);
        solve(root->right, path, result);
    }
};
