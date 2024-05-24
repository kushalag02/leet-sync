class Solution {
public:
    int minimumPushes(string word) {
        vector<int> A(26, 0);
        int ans = 0;
        for (char c : word) {
            A[c - 'a']++;
        }
        sort(begin(A), end(A));
        reverse(begin(A), end(A));
        for (int i = 0; i < 26; i++) {
            ans += (1 + i / 8) * A[i];
        }
        return ans;
    }
};