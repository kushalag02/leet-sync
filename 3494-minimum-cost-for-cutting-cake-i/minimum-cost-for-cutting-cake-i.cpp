class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(begin(h), end(h));
        sort(begin(v), end(v));

        long long int sumH = 0;
        long long int sumV = 0;

        for (int i : h) {
            sumH += i;
        }
        for (int i : v) {
            sumV += i;
        }

        long long int ans = 0;

        int i = m - 2;
        int j = n - 2;
        while (i >= 0 && j >= 0) {
            if (h[i] > v[j]) {
                ans += h[i] + sumV;
                sumH -= h[i];
                i--;
            } else {
                ans += v[j] + sumH;
                sumV -= v[j];
                j--;
            }
        }

        while (i >= 0) {
            ans += h[i];
            i--;
        }
        while (j >= 0) {
            ans += v[j];
            j--;
        }
        return ans;
    }
};