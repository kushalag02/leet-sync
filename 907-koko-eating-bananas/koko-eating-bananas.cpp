class Solution {
public:
    int countTime(vector<int>& piles, int k) {
        int time = 0;
        for (int i : piles) {
            if (i % k != 0) {
                time++;
            }

            time += (i / k);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if (h < n) {
            return -1;
        } else if (h == n)
            return *max_element(piles.begin(), piles.end());
        else {
            int left = 1;
            // int right = n - 1;
            int right = *max_element(piles.begin(), piles.end());
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (countTime(piles, mid) <= h) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }
    }
};
