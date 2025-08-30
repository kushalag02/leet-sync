class Solution {
public:
    // solve for number of subarrays with at most k distinct
    // If we use general sliding windo we can miss some counts

    // soln - https://youtu.be/7wYGbV_LsX4?si=p55q6kY-hU28Hggu
    
    int solve(vector<int>& nums, int k) {
        int l = 0;
        long long count = 0;
        map<int, int> mp;

        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;

            while ((int)mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }

            count += (r - l + 1);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
