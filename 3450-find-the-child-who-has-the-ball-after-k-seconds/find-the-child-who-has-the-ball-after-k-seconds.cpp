class Solution {
public:
    int numberOfChild(int n, int k) {
        int pos = 0;
        int flag = 1;
        while (k--) {
            if (flag == 1) {
                if (pos == n - 1)
                    flag = -1;
                pos += flag;
            } else {
                if (pos == 0)
                    flag = 1;
                pos += flag;
            }
        }
        return pos;
    }
};