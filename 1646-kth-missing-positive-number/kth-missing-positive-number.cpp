class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        int ans = 1;
        int i = 0;

        while (count < k) {
            if (i < arr.size() && arr[i] == ans) {
                i++;
            } else {
                count++;
                if (count == k) {
                    return ans;
                }
            }
            ans++;
        }
        return ans;
    }
};
