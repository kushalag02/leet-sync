class Solution {
public:
    int passThePillow(int n, int time) {
        int temp = time % (2 * (n - 1));
        if (n > temp) {
            return temp + 1;
        } else {
            return 2 * n - temp - 1;
        }
    }
};