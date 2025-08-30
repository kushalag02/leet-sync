class Solution {
public:
    bool checkValid(vector<vector<int>>& A) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            map<char, int> mp;
            for (int j = 0; j < n; j++) {
                char c = A[i][j];
                if (c != '.') {
                    if (mp[c] == 1)
                        return false;
                    mp[c] = 1;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            map<char, int> mp;
            for (int i = 0; i < n; i++) {
                char c = A[i][j];
                if (c != '.') {
                    if (mp[c] == 1)
                        return false;
                    mp[c] = 1;
                }
            }
        }
        return true;
    }
};