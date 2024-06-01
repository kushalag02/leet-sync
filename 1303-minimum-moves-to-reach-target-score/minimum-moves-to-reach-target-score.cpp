class Solution {
public:
    int minMoves(int n, int d) {
        int count = 0;
        if (d == 0)
            return n - 1;

        while (n > 1 && d > 0) {
            if (n % 2 == 1) {
                n--;
            } else {
                d--;
                n /= 2;
            }
            count++;
        }

        return count + n - 1;
    }
};
