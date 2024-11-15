class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& A) {
        int n = A.size();
        int left = 0;
        while (left + 1 < n && A[left] <= A[left + 1]) {
            left++;
        }
        if (left == n - 1) {
            return 0;
        }

        int right = n - 1;
        while (right > 0 && A[right - 1] <= A[right]) {
            right--;
        }
        int result = min(n - left - 1, right);
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (A[i] <= A[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};
