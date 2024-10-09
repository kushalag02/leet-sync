class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);

        if (l1 > l2) {
            return false;
        }
        
        for (char c : s1) {
            mp1[c - 'a']++;
        }

        for (int i = 0; i < l1; i++) {
            mp2[s2[i] - 'a']++;
        }

        if (mp1 == mp2) {
            return true;
        }

        for (int i = l1; i < l2; i++) {
            mp2[s2[i] - 'a']++;
            mp2[s2[i - l1] - 'a']--;

            if (mp1 == mp2) {
                return true;
            }
        }

        return false;
    }
};
