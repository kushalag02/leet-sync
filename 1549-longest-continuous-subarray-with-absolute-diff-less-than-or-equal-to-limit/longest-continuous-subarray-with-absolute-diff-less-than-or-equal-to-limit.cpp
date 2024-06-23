class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        deque<int> inc;
        deque<int> dec;
        int maxi = 0;
        int left = 0;

        for (int i = 0; i < A.size(); i++) {
            while (!inc.empty() && A[i] < inc.back()) {
                inc.pop_back();
            }
            inc.push_back(A[i]);

            while (!dec.empty() && A[i] > dec.back()) {
                dec.pop_back();
            }
            dec.push_back(A[i]);

            while (dec.front() - inc.front() > limit) {
                if (A[left] == dec.front()) {
                    dec.pop_front();
                }
                if (A[left] == inc.front()) {
                    inc.pop_front();
                }
                left++;
            }

            maxi = max(maxi, i - left + 1);
        }

        return maxi;
    }
};