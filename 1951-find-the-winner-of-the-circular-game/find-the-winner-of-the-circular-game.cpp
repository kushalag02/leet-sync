class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
            return 1;

        // The recursive call:
        // We use the result of the subproblem (with n-1 people) to find the
        // result for n people The position returned by the recursive call will
        // be offset by k positions The modulus operation ensures we wrap around
        // the circle properly
        return (findTheWinner(n - 1, k) + k - 1) % n + 1;
    }
};
