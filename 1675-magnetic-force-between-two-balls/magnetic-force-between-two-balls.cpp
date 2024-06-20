class Solution {
public:
    int maxDistance(vector<int>& A, int m) {
        // aggresive cows concept
        sort(A.begin(), A.end());
        int n = A.size();
        int left = 1;
        int right = (A[n - 1] - A[0]) / (m - 1);
        int ans = 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (solve(A, mid, m) == true) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    bool solve(const vector<int>& A, int dist, int balls) {
        int count = 1;
        int last = A[0];
        for (int i = 1; i < A.size(); i++) {
            if (A[i] - last >= dist) {
                count++;
                last = A[i];
            }
            if (count >= balls) {
                return true;
            }
        }
        return false;
    }
};