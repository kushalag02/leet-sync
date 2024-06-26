class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unionSets(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);
        if (aRoot != bRoot) {
            if (rank[aRoot] < rank[bRoot]) {
                parent[aRoot] = bRoot;
            } else if (rank[aRoot] > rank[bRoot]) {
                parent[bRoot] = aRoot;
            } else {
                parent[aRoot] = bRoot;
                rank[bRoot]++;
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (string s : equations) {
            if (s[1] == '=' && s[2] == '=') {
                unionSets(s[0] - 'a', s[3] - 'a');
            }
        }
        for (string s : equations) {
            if (s[1] == '!' && s[2] == '=') {
                if (find(s[0] - 'a') == find(s[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;
    }
};