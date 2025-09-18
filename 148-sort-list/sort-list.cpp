class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return head;

        vector<int> A;
        ListNode* curr = head;
        while (curr != NULL) {
            A.push_back(curr->val);
            curr = curr->next;
        }
        sort(A.begin(), A.end());
        curr = head;
        int i = 0;
        while (curr != NULL) {
            curr->val = A[i];
            i++;
            curr = curr->next;
        }

        return head;
    }
};
