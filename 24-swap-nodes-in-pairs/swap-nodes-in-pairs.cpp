class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};