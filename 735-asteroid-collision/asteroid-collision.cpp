class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        stack<int> st;

        for (int i : A) {
            bool flag = false;
            while (st.empty() == false && i < 0 && st.top() > 0) {
                if (st.top() < -i) {
                    st.pop();
                    continue;
                } else {
                    flag = true;
                    if (st.top() == -i) {
                        st.pop();
                    }
                    break;
                }
            }
            if (flag == false) {
                st.push(i);
            }
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
