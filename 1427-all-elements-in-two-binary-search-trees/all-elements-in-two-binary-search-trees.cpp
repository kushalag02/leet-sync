class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> A;
        vector<int> B;
        makeVector(root1, A);
        makeVector(root2, B);
        int n = A.size();
        int m = B.size();
        vector<int> ans(n + m);
        for (int i = 0; i < n; i++) {
            ans[i] = A[i];
        }
        for (int i = 0; i < m; i++) {
            ans[i + n] = B[i];
        }
        sort(begin(ans), end(ans)); // Better to use merge sort for this sorting
        return ans;
    }
    void makeVector(TreeNode* root, vector<int>& A) {
        if (root == nullptr)
            return;
        A.push_back(root->val);
        makeVector(root->left, A);
        makeVector(root->right, A);
    }
};