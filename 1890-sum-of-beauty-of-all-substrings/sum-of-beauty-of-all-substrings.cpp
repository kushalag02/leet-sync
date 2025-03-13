class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> mp(26, 0);
            for (int j = i; j < n; j++) {
                mp[s[j] - 'a']++;
                int maxi = 0;
                int mini = INT_MAX;
                
                for (int k = 0; k < mp.size(); k++) {
                    
                    if (mp[k] > 0) {
                        maxi = max(maxi, mp[k]);
                        mini = min(mini, mp[k]);
                    }
                }
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};
