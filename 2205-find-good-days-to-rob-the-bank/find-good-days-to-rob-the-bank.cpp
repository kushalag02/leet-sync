class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& A, int time) {
        int n = A.size();
        vector<int> up(n, 0), down(n, 0);
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            if (A[i + 1] <= A[i]) {
                down[i + 1] = down[i] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] <= A[i + 1]) {
                up[i] = up[i + 1] + 1;
            }
        }
        for (int i = time; i < n - time; i++) {
            if (down[i] >= time && up[i] >= time) {
                ans.push_back(i);
            }
        }
        // reverse(ans.begin(), ans.end());

        return ans;
    }
};
