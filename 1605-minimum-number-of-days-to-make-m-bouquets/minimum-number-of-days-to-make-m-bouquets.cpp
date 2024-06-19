#define ll long long int
class Solution {
public:
    bool solve(const vector<int>& A, int day, int m, int k) {
        int bouquets = 0;
        int flowers = 0;

        for (int i : A) {
            if (i <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        if (bouquets >= m)
            return true;
        else
            return false;
    }

    int minDays(vector<int>& A, int m, int k) {
        ll n = A.size();
        if (n < (ll)m * k) {
            return -1;
        }

        int left = *min_element(A.begin(), A.end());
        int right = *max_element(A.begin(), A.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (solve(A, mid, m, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
