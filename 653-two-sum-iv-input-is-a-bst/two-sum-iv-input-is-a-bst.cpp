class Solution {
public:
    void inorder(TreeNode* root, vector<int>& A) {
        if (!root)
            return;
        inorder(root->left, A);
        A.push_back(root->val);
        inorder(root->right, A);
    }

    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;
        vector<int> A;
        inorder(root, A);
        int n = A.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int sum = A[l] + A[r];
            if (sum > k) {
                r--;
            } else if (sum < k) {
                l++;
            } else {
                return true;
            }
        }
        return false;
    }
};