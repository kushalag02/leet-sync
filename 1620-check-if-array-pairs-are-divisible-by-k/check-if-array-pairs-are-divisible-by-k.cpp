class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (int i : arr) {
            int rem = i % k;
            if (rem < 0) {
                rem += k;
            }
            mp[rem]++;
        }
        for (auto& itr : mp) {
            if (itr.first == 0) {
                if (itr.second % 2 != 0)
                    return false;
            } else {
                int left = (k - itr.first) % k;
                if (mp[itr.first] != mp[left])
                    return false;
            }
        }

        return true;
    }
};
