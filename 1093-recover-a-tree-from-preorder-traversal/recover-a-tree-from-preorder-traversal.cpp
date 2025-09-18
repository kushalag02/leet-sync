class Solution {
public:
    TreeNode* recoverFromPreorder(string s) { return dfs(s, 0); }
    int i = 0;

    TreeNode* dfs(string& s, int depth) {
        int n = s.size();
        int d = 0;
        int j = i;

        while (j < n && s[j] == '-') {
            d++;
            j++;
        }
        if (d != depth) {
            return nullptr;
        }

        // Calulating value of the node to be created
        int val = 0;
        while (j < n && isdigit(s[j])) {
            val = val * 10;
            val += (s[j] - '0');
            j++;
        }
        i = j;

        TreeNode* node = new TreeNode(val);
        node->left = dfs(s, depth + 1);
        node->right = dfs(s, depth + 1);

        return node;
    }
};
