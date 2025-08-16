class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 || k == 1)
            return 0;
        
        //            0
        //          01 10
        //       01 10 10 01
        // 01 10 10 01 10 01 01 10
        // Mid ke pehle same as above row and mid ke baad uska not hogya ha
        
        int size = pow(2, n - 1);
        int mid = (size + 1) / 2;
        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            return !kthGrammar(n - 1, k - mid); // iska not lena hoga
        }
    }
};