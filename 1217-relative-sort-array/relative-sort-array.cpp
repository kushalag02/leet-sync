class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int i : arr1) {
            mp[i]++;
        }
        vector<int> ans;
        for (int num : arr2) {
            int count = mp[num];
            while (count--) {
                ans.push_back(num);
                mp[num]--;
            }
        }
        vector<int> rem;
        for (auto& itr : mp) {
            int temp = itr.second;
            while (temp--) {
                rem.push_back(itr.first);
                itr.second--;
            }
        }
        sort(begin(rem), end(rem));
        for (int i : rem) {
            ans.push_back(i);
        }
        return ans;
    }
};