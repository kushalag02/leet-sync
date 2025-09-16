class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> A;

        for (int num : nums) {
            A.push_back(num);
            while (A.size() > 1) {
                int a = A.back();
                A.pop_back();
                int b = A.back();
                A.pop_back();
                int g = gcd(a, b);

                if (g > 1) {
                    long long lcm = 1LL * a * b / g;
                    A.push_back((int)lcm);
                } else {
                    A.push_back(b);
                    A.push_back(a);
                    break;
                }
            }
        }
        return A;
    }
};