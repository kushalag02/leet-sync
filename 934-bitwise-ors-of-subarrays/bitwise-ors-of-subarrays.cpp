class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> st;
        set<int> cur;

        for (int i : arr) {
            set<int> next;
            next.insert(i);
            for (int x : cur) {
                next.insert(x | i);
            }
            cur = next;
            st.insert(cur.begin(), cur.end());
        }
        return st.size();
    }
};
