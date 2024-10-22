class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == NULL) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<long long> lvlSum;

        while (!q.empty()) {
            int n = q.size();
            long long levelSum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            lvlSum.push_back(levelSum);
        }

        sort(lvlSum.rbegin(), lvlSum.rend());

        if (k >= 1 && k <= lvlSum.size()) {
            return lvlSum[k - 1];
        } else {
            return -1;
        }
    }
};