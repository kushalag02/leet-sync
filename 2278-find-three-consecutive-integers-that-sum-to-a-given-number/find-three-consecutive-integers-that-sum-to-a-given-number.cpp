class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3 != 0)
            return {};
        if (num == 4)
            return {};
        vector<long long> ans;
        long long first = num / 3 - 1;
        ans.push_back(first);
        ans.push_back(first + 1);
        ans.push_back(first + 2);
        return ans;
    }
};