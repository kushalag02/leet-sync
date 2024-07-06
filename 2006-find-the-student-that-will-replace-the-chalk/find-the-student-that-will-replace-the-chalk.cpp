class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += chalk[i];
        }
        long long int rem = k % ans;
        for (int i = 0; i < n; i++) {
            if (rem < chalk[i]) {
                return i;
            }
            rem -= chalk[i];
        }
        return 0;
    }
};