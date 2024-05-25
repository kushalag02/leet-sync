class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        int maxi = 0;

        sort(begin(special), end(special));
        maxi = special[0] - bottom;
        for (int i = 1; i < n; i++) {
            int diff = special[i] - special[i - 1] - 1;
            maxi = max(maxi, diff);
        }
        maxi = max(maxi, top - special[n - 1]);
        return maxi;
    }
};