class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        pair<int, int> p1 = {edges[0][0], edges[0][1]};
        pair<int, int> p2 = {edges[1][0], edges[1][1]};
        if (p1.first == p2.first || p1.first == p2.second) {
            return p1.first;
        } else {
            return p1.second;
        }
    }
};