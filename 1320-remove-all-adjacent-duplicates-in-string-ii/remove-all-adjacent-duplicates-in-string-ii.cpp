class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char c : s) {
            if (st.empty() != true && st.top().first == c) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({c, 1});
            }
        }
        string result;
        while (st.empty() != true) {
            result.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};