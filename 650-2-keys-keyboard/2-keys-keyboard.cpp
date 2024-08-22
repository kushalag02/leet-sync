class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        int copy = 0;
        int paste = 1;
        int ops = 0;

        while (paste != n) {
            if (n % paste == 0) {
                copy = paste;
                ops++;
            }
            paste += copy;
            ops++;
        }
        return ops;
    }
};