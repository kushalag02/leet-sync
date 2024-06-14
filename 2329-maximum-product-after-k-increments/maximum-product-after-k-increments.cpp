class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        long long ans = 1;
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < nums.size(); i++) {
            que.push(nums[i]);
        }

        while (k--) {
            int num = que.top();
            que.pop();
            que.push(num + 1);
        }

        while (que.empty() == false) {
            ans = (ans * que.top()) % MOD;
            que.pop();
        }

        return ans % MOD;
    }
};