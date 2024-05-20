class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int j = 0;
        int count = 0;
        for (int i = 0; i < magazine.length(); i++) {
            if (magazine[i] == ransomNote[j]) {
                j++;
                count++;
            }
        }
        if (count == ransomNote.length()) {
            return true;
        }
        return false;
    }
};