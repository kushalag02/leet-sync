class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> Id;
        unordered_map<string, string> AcName;
        int id = 0;

        for (auto account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                if (Id.find(account[i]) == Id.end()) {
                    Id[account[i]] = id++;
                    AcName[account[i]] = name;
                }
            }
        }

        parent.resize(id);
        rank.resize(id, 0);
        for (int i = 0; i < id; ++i) {
            parent[i] = i;
        }

        for (auto account : accounts) {
            int first = Id[account[1]];
            for (int i = 2; i < account.size(); i++) {
                unionSets(first, Id[account[i]]);
            }
        }

        unordered_map<int, vector<string>> cmp;
        for (auto pair : Id) {
            int root = find(pair.second);
            cmp[root].push_back(pair.first);
        }

        // Output

        vector<vector<string>> final;
        for (auto component : cmp) {
            vector<string> emails = component.second;
            sort(begin(emails), end(emails));
            emails.insert(emails.begin(), AcName[emails[0]]);
            final.push_back(emails);
        }

        return final;
    }
};