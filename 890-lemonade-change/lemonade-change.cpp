class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int total5 = 0;
        int total10 = 0;

        for (int cost : bills) {
            if (cost == 5) {
                total5++;
            } else if (cost == 10) {
                if (total5 != 0) {
                    total10++;
                    total5--;
                } else {
                    return false;
                }
            } else if (cost == 20) {
                if (total10 != 0 && total5 != 0) {
                    total10--;
                    total5--;
                } else if (total5 >= 3) {
                    total5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
