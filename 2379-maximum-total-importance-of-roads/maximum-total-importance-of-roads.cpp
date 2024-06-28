class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            deg[u]++;
            deg[v]++;
        }
        
        vector<int> nodes(n);
        for (int i = 0; i < n; i++) {
            nodes[i] = i;
        }
        
        sort(nodes.begin(), nodes.end(), [&deg](int a, int b) { return deg[a] > deg[b]; });
        
        vector<int> imp(n);
        for (int i = 0; i < n; i++) {
            imp[nodes[i]] = n - i;
        }
        
        long long ans = 0;
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            ans += imp[u] + imp[v];
        }
        
        return ans;
    }
};
