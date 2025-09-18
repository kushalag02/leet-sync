/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
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