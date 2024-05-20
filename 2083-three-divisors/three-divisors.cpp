class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1)
            return false;
        if (num <= 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }
    bool isThree(int n) {
        // Only possible if it is a sqaure of a prime number 
        int i = sqrt(n);
        if (i * i != n)
            return false;
        return isPrime(i);
    }
};