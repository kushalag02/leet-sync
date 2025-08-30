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

    int minSwapsCouples(vector<int>& row) {
        // ans = N - no. of connected components
        int n = row.size() / 2;

        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < row.size(); i += 2) {
            int a = row[i] / 2;
            int b = row[i + 1] / 2;
            unionSets(a, b);
        }

        unordered_set<int> st; // count number of conn. comp.
        for (int i = 0; i < n; i++) {
            st.insert(find(i));
        }

        return n - st.size();
    }
};
