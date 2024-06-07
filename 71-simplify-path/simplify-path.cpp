class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        string final = "";
        int n = s.size();

        for (int i = 0; i < n;) {
            while (i < n && s[i] == '/')
                i++;
            string temp;
            while (i < n && s[i] != '/') {
                temp += s[i];
                i++;
            }
            if (temp == "" || temp == ".") {
                continue;
            } else if (temp == "..") {
                if (st.empty() == false)
                    st.pop();
            } else {
                st.push(temp);
            }
        }
        while (st.empty() == false) {
            final = "/" + st.top() + final;
            st.pop();
        }
        if (final.empty() == false)
            return final;
        else
            return "/";
    }
};
