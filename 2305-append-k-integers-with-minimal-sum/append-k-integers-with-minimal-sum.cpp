class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = 0;
            }
        }
        vector<int> A;
        for (int i : nums) {
            if (i != 0) {
                A.push_back(i);
            }
        }
        long long ans = 0;
        long long prev = 0;

        for (int i = 0; i < A.size() && k > 0; i++) {
            long long diff = A[i] - prev - 1;
            if (diff > 0) {
                long long take = min((long long)k, diff);
                long long start = prev + 1;
                long long end = prev + take;
                ans += (start + end) * take / 2;
                k -= take;
            }
            prev = A[i];
        }

        if (k > 0) {
            long long start = prev + 1;
            long long end = prev + k;
            ans += (start + end) * k / 2;
        }
        return ans;
    }
};