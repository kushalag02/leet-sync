// Constructer
bool compare(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
}
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> vp(256, {0, 0});
        for (char ch : s) {
            vp[ch].first = ch;
            vp[ch].second++;
        }
        vector<pair<char, int>> freq;
        for (int i = 0; i < vp.size(); i++) {
            if (vp[i].second > 0) {
                freq.push_back(vp[i]);
            }
        }
        sort(freq.begin(), freq.end(), compare);
        string ans;
        for (int i = 0; i < freq.size(); i++) {
            for (int j = 0; j < freq[i].second; j++) {
                ans += freq[i].first;
            }
        }

        return ans;
    }
};
