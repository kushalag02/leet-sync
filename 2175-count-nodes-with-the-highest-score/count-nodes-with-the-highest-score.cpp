class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& A, vector<int>& size,
            long long& maxi, int& count, int n) {
        int total = 1;
        long long score = 1;

        for (int child : A[node]) {
            if (child == parent)
                continue;
            int sz = dfs(child, node, A, size, maxi, count, n);
            total += sz;
            score *= sz;
        }

        int rest = n - total;
        if (rest > 0)
            score *= rest;

        if (score > maxi) {
            maxi = score;
            count = 1;
        } else if (score == maxi) {
            count++;
        }

        size[node] = total;
        return total;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> A(n);
        vector<int> size(n, 0);
        long long maxi = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (parents[i] != -1) {
                A[i].push_back(parents[i]);
                A[parents[i]].push_back(i);
            }
        }

        dfs(0, -1, A, size, maxi, count, n);
        return count;
    }
};
