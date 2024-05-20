class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& A) {
        unordered_map<int, int> mp;
        vector<vector<int>> result(2);

        for (int i = 0; i < A.size(); i++) {
            if (mp.find(A[i][0]) == mp.end())
                mp[A[i][0]] = 0;

            mp[A[i][1]]++;
        }

        vector<int> winner;
        vector<int> lozer;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second == 0)
                winner.push_back(it->first);
            else if (it->second == 1)
                lozer.push_back(it->first);
        }

        sort(winner.begin(), winner.end());
        sort(lozer.begin(), lozer.end());
        result[0] = winner;
        result[1] = lozer;

        return result;
    }
};
