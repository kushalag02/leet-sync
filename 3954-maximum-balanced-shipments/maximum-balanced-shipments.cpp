class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int maxi = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, weight[i]);
            if (weight[i] < maxi) {
                maxi = 0;
                count++;
            }
        }
        return count;
    }
};