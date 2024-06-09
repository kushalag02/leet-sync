class Solution {
public:
    int maxAscendingSum(vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0; 
        
        int sum = A[0];
        int maxi = A[0];
        
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                sum += A[i];
            } else {
                maxi = max(sum, maxi);
                sum = A[i];
            }
        }
        
        maxi = max(sum, maxi); 
        
        return maxi;
    }
};
