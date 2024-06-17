class Solution {
public:
    int hIndex(vector<int>& A) {
        int n = A.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] >= n - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return n - left;
    }
};