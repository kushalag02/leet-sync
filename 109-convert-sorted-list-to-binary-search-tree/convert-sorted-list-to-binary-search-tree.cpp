class Solution {
public:
    TreeNode* makeTree(vector<int>& A, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(A[mid]);
        node->left = makeTree(A, left, mid - 1);
        node->right = makeTree(A, mid + 1, right);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> A;
        while (head != NULL) {
            A.push_back(head->val);
            head = head->next;
        }
        return makeTree(A, 0, A.size() - 1);
    }
};