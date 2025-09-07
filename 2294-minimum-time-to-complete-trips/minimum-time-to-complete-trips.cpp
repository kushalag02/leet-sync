class Solution {
public:
    bool solve(vector<int> time, long long tm, int totalTrips) {
        long long trips = 0;
        for (int i : time) {
            trips += (tm / i);
            if (trips >= totalTrips) {
                return true;
            }
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long low = -1;
        long long high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        while (low + 1 < high) {
            long long mid = low + (high - low) / 2;
            if (solve(time, mid, totalTrips)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    }
};