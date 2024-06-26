class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;

        for (int num : nums) {
            for (int i = 2; i <= sqrt(num); i++) {
                while (num % i == 0) {
                    st.insert(i);
                    num /= i;
                }
            }
            if (num > 1) {
                st.insert(num);
            }
        }

        return st.size();
    }
};
