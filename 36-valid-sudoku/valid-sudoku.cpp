class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& A) {
        for (int i = 0; i < 9; i++) {
            map<char, int> mp;
            for (int j = 0; j < 9; j++) {
                char c = A[i][j];
                if (c != '.') {
                    if (mp[c] == 1)
                        return false;
                    mp[c] = 1;
                }
            }
        }

        for (int j = 0; j < 9; j++) {
            map<char, int> mp;
            for (int i = 0; i < 9; i++) {
                char c = A[i][j];
                if (c != '.') {
                    if (mp[c] == 1)
                        return false;
                    mp[c] = 1;
                }
            }
        }

        for (int nr = 0; nr < 3; nr++) {
            for (int nc = 0; nc < 3; nc++) {
                map<char, int> mp;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = A[nr * 3 + i][nc * 3 + j];
                        if (c != '.') {
                            if (mp[c] == 1)
                                return false;
                            mp[c] = 1;
                        }
                    }
                }
            }
        }

        return true;
    }
};
