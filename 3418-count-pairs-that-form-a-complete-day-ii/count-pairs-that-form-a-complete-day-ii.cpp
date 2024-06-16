class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> mp;
        long long count = 0;

        for (int i : hours) {
            int rem = i % 24;
            int left = (24 - rem) % 24;
            if (mp.find(left) != mp.end())
                count += mp[left];

            mp[rem]++;
        }

        return count;
    }
};