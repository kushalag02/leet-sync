class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        vector<int> A;
        vector<int> B;
        ListNode* curr = head;

        int n = 0;
        while (curr) {
            n++;
            curr = curr->next;
        }
        curr = head;
        int i = 0;
        while (curr) {
            if (i < (n + 1) / 2) {
                A.push_back(curr->val);
            } else {
                B.push_back(curr->val);
            }
            i++;
            curr = curr->next;
        }

        reverse(B.begin(), B.end());

        curr = head;
        int p1 = 0;
        int p2 = 0;
        int flag = 0;
        while (curr) {
            if (flag == 0 && p1 < A.size()) {
                curr->val = A[p1];
                p1++;
                flag = 1;
            } else if (flag == 1 && p2 < B.size()) {
                curr->val = B[p2];
                p2++;
                flag = 0;
            }
            curr = curr->next;
        }
    }
};
