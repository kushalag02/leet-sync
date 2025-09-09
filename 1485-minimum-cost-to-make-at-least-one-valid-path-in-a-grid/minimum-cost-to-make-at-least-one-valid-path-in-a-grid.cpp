class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // Good question of 0/1 BFS
        // See solution again
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int cost = 0;
                if (grid[x][y] != i + 1) {
                    cost = 1;
                }

                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
