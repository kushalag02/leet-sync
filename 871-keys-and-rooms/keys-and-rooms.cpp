class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        stack<int> st;

        st.push(0);
        vis[0] = true;

        while (st.empty() == false) {
            int room = st.top();
            st.pop();
            for (auto i : rooms[room]) {
                if (vis[i] == 0) {
                    vis[i] = 1;
                    st.push(i);
                }
            }
        }
        for (int i : vis) {
            if (i == 0) {
                return false;
            }
        }

        return true;
    }
};