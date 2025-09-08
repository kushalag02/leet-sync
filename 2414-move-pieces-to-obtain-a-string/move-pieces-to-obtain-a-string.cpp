class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();

        string s1;
        string s2;
        for (char c : start) {
            if (c != '_')
                s1.push_back(c);
        }
        for (char c : target) {
            if (c != '_')
                s2.push_back(c);
        }

        if (s1 != s2)
            return false;

        int i = 0;
        int j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == '_')
                i++;
            while (j < n && target[j] == '_')
                j++;
            if (i == n || j == n)
                break;

            if (start[i] == 'L' && i < j)
                return false;
            if (start[i] == 'R' && i > j)
                return false;
            i++;
            j++;
        }

        return true;
    }
};