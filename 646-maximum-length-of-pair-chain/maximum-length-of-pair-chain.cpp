bool comparator(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comparator);
        int ans = 0;
        int last = INT_MIN;
        for (int i = 0; i < pairs.size(); i++) {
            if (last < pairs[i][0]) {
                ans++;
                last = pairs[i][1];
            }
        }
        return ans;
    }
};