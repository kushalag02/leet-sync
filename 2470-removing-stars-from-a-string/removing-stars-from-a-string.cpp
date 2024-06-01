class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<char> st;
        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*')
                st.pop();
            else
                st.push(s[i]);
        }
        while (st.empty() != true) {
            char c = st.top();
            ans += c;
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};