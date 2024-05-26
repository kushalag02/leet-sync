class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> A;
        A = levelOrder(root);
        for (int i = 0; i < A.size(); i++) {
            if (i % 2 == 0) {
                if (increase(A[i]) == false || Odd(A[i]) == false)
                    return false;
            } else {
                if (decrease(A[i]) == false || Even(A[i]) == false)
                    return false;
            }
        }
        return true;
    }

    bool increase(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] <= nums[i])
                return false;
        }
        return true;
    }

    bool decrease(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] >= nums[i])
                return false;
        }
        return true;
    }

    bool Odd(vector<int>& nums) {
        for (int num : nums) {
            if (num % 2 == 0)
                return false;
        }
        return true;
    }

    bool Even(vector<int>& nums) {
        for (int num : nums) {
            if (num % 2 != 0)
                return false;
        }
        return true;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            result.push_back(level);
        }
        return result;
    }
};