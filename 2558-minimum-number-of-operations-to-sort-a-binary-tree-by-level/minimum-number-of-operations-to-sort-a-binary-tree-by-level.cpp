class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (root == NULL)
            return 0;
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            result.push_back(level);
        }

        // Main logic is how to check the number of swaps in an array
        int swaps = 0;
        for (auto level : result) {
            vector<int> temp = level;
            sort(temp.begin(), temp.end());

            unordered_map<int, int> mp;
            for (int i = 0; i < temp.size(); i++) {
                mp[temp[i]] = i;
            }

            vector<int> vis(temp.size(), 0);
            for (int i = 0; i < level.size(); i++) {
                if (vis[i] == 1 || mp[level[i]] == i) {
                    continue;
                }

                int cycleSize = 0;
                int x = i;
                while (!vis[x]) {
                    vis[x] = 1;
                    x = mp[level[x]];
                    cycleSize++;
                }
                if (cycleSize > 0) {
                    swaps += (cycleSize - 1);
                }
            }
        }
        return swaps;
    }
};