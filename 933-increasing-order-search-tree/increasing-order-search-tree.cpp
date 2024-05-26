class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        makeArr(root, ans);
        sort(begin(ans), end(ans));
        return makeTree(ans);
    }
    TreeNode* makeTree(vector<int>& nums) {
        if (nums.empty())
            return nullptr;

        TreeNode* root = new TreeNode(nums[0]);
        TreeNode* current = root;

        for (int i = 1; i < nums.size(); i++) {
            current->right = new TreeNode(nums[i]);
            current = current->right;
        }

        return root;
    }
    void makeArr(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        ans.push_back(root->val);
        makeArr(root->left, ans);
        makeArr(root->right, ans);
    }
};