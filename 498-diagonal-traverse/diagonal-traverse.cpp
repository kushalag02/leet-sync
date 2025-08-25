class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push({0, 0});

        vis[0][0] = 1;

        int flag = 1;

        while (!q.empty()) {
            // Same logic for zig-zagg order traversal in a binary tree
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                level.push_back(mat[r][c]);

                if (r + 1 < m && vis[r + 1][c] == 0) {
                    q.push({r + 1, c});
                    vis[r + 1][c] = 1;
                }
                if (c + 1 < n && vis[r][c + 1] == 0) {
                    q.push({r, c + 1});
                    vis[r][c + 1] = 1;
                }
            }

            if (!flag) {
                reverse(level.begin(), level.end());
            }
            flag = !flag;
            ans.insert(ans.end(), level.begin(), level.end());
        }

        return ans;
    }
};