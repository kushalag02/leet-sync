class Solution {
public:
    bool canReach(vector<int>& A, int start) {
        // Tough to think about bfs
        // once realize it is a bfs, code is easy
        int n = A.size();
        queue<int> q;
        vector<int> vis(n, 0);

        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (A[idx] == 0)
                return 1;

            int n1 = idx + A[idx];
            if (n1 < n && vis[n1] == 0) {
                vis[n1] = 1;
                q.push(n1);
            }
            int n2 = idx - A[idx];
            if (n2 >= 0 && vis[n2] == 0) {
                vis[n2] = 1;
                q.push(n2);
            }
        }
        return 0;
    }
};
