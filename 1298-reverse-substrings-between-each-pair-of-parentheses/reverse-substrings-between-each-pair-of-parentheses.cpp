class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        if (n <= 2) {
            return "";
        }
        string ans = "";
        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                string temp = "";
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                for (char c : temp) {
                    st.push(c);
                }
            } else {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};