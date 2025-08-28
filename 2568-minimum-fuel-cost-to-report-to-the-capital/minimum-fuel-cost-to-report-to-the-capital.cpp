class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> A(n + 1);

        for (auto& a : roads) {
            int u = a[0];
            int v = a[1];
            A[u].push_back(v);
            A[v].push_back(u);
        }

        long long ans = 0;
        dfs(A, 0, -1, seats, ans);
        return ans;
    }

    int dfs(vector<vector<int>>& A, int u, int prev, int seats,
            long long& ans) {
        int num = 1;
        for (int v : A[u]) {
            if (v == prev)
                continue;
            num += dfs(A, v, u, seats, ans);
        }
        if (u > 0) {
            ans += (num + seats - 1) / seats;
        }
        return num;
    }
};
