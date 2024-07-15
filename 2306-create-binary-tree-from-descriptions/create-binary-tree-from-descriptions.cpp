class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& A) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> st;

        for (auto it : A) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (mp.find(u) == mp.end()) {
                mp[u] = new TreeNode(u);
            }

            if (mp.find(v) == mp.end()) {
                mp[v] = new TreeNode(v);
            }

            if (w) {
                mp[u]->left = mp[v];
            } else {
                mp[u]->right = mp[v];
            }

            st.insert(v);
        }
        TreeNode* root = NULL;
        for (auto it : mp) {
            if (st.find(it.first) == st.end()) {
                root = it.second;
                break;
            }
        }

        return root;
    }
};