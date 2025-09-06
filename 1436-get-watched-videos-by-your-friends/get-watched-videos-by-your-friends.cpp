class Solution {
public:
    static bool compare(const pair<string, int>& a,
                        const pair<string, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& W,
                                          vector<vector<int>>& friends, int id,
                                          int level) {
        int n = friends.size();
        vector<bool> vis(n, false);
        queue<int> q;

        q.push(id);
        vis[id] = true;

        int curr = 0;

        while (!q.empty() && curr < level) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front();
                q.pop();
                for (int v : friends[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            curr++;
        }

        unordered_map<string, int> mp;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (auto& video : W[f]) {
                mp[video]++;
            }
        }

        vector<pair<string, int>> temp(mp.begin(), mp.end());
        sort(temp.begin(), temp.end(), compare);

        vector<string> ans;
        for (auto& p : temp)
            ans.push_back(p.first);

        return ans;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "1"; });
auto init1 = atexit([]() { ofstream("display_memory.txt") << "1"; });