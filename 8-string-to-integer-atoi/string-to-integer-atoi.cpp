class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        int flag = 1;
        int i = 0;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        if (s[i] == '+')
            i++;
        else if (s[i] == '-') {
            i++;
            flag = -1;
        }
        while (i < s.length()) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10;
                ans += (s[i] - '0');
                if (ans > INT_MAX && flag == -1)
                    return INT_MIN;
                else if (ans > INT_MAX && flag == 1)
                    return INT_MAX;
                i++;
            }

            else {
                return ans * flag;
            }
        }
        return ans * flag;
    }
};