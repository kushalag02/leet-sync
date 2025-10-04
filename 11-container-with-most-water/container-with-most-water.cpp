class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        long long int count = 0;

        while (l < r) {
            long long int width = r - l;
            long long int h = min(height[l], height[r]);
            long long int water = width * h;
            count = max(count, water);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return count;
    }
};