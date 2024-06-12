class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        set<int> st;  
        vector<set<int>> dp(n);

        dp[0].insert(arr[0]);
        st.insert(arr[0]);

        for (int i = 1; i < n; i++) {
            dp[i].insert(arr[i]);
            st.insert(arr[i]);

            for (int x : dp[i - 1]) {
                dp[i].insert(x | arr[i]);
                st.insert(x | arr[i]);
            }
        }

        return st.size();
    }
};
