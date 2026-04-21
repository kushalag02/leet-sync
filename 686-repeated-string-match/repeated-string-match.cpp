class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int minRepeat = b.size() / a.size();
        string s = "";
        minRepeat+=2;
        int ans = 0; 

        while(minRepeat--){
            ans++;
            s += a;
            if(s.find(b) != string::npos){  // correct condition
                return ans;
            }
        }
        return -1;
    }
};