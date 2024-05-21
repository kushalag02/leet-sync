class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        
        string last = countAndSay(n - 1);
        stringstream ans;
        int count = 1;

        char current = last[0];
        for (int i = 1; i < last.size(); i++) {
            if (last[i] != current) {
                ans << count << current;
                count = 1;
                current = last[i];
            } else {
                count++;
            }
        }
        ans << count << current;
        return ans.str();
    }
};
