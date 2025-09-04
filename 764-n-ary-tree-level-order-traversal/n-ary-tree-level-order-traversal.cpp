class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        solve(root, ans, 0);
        return ans;
    }

    void solve(Node* root, vector<vector<int>>& ans, int level) {
        if (!root)
            return;

        if (level == ans.size()) {
            ans.push_back(vector<int>());
        }

        ans[level].push_back(root->val);
        for (auto child : root->children) {
            solve(child, ans, level + 1);
        }
    }
};