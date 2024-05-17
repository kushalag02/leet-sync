class Solution {
public:
    int countPrimes(int n) {
        // Normal approach giving TLE
        // See Striver video fro this question
        // Solving using this method is efficient approach
        if (n <= 2) {
            return 0;
        }
        int count = 0;
        vector<int> isPrime(n + 1, 1);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i] == 1)
                for (int j = 2 * i; j <= n; j += i)
                    isPrime[j] = 0;
        }
        for (int i = 2; i < n; i++) {
            if (isPrime[i] == 1)
                count++;
        }
        return count;
    }
};