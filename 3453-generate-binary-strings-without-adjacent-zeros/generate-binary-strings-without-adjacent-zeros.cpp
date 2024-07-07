class Solution {
public:
    vector<string> validStrings(int n) {
        if (n == 1) {
            return {"0", "1"};
        }

        vector<string> A = {"0", "1"};

        for (int i = 0; i < n - 1; i++) {
            vector<string> vp;

            for (string s : A) {
                int size = s.length();
                if (s[size - 1] == '1') { // 101
                    vp.push_back(s + '0');
                    vp.push_back(s + '1');
                } else {
                    vp.push_back(s + '1'); // 01
                }
            }
            A = vp;
        }
        return A;
    }
};