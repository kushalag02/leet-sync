class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp;
        unordered_set<char> count;
        stack<char> st;
        for (char ch : s) {
            mp[ch]++;
        }
        for (char ch : s) {
            mp[ch]--;
            if (count.find(ch) != count.end()) {
                continue;
            }
            while (st.empty() != true && st.top() > ch && mp[st.top()] > 0) {
                count.erase(st.top());
                st.pop();
            }
            st.push(ch);
            count.insert(ch);
        }
        string ans = "";
        while (!st.empty()) {
            char c = st.top();
            ans += c;
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
