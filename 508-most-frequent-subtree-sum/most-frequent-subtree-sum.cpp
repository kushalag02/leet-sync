class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        unordered_map<int, int> mp;
        int maxi = 0;

        subtreeSum(root, mp, maxi);

        vector<int> ans;
        for (auto it : mp) {
            if (it.second == maxi) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
    int subtreeSum(TreeNode* root, unordered_map<int, int>& mp, int& maxi) {
        if (root == NULL) {
            return 0;
        }

        int left = subtreeSum(root->left, mp, maxi);
        int right = subtreeSum(root->right, mp, maxi);

        int node = root->val + left + right;
        mp[node]++;
        maxi = max(maxi, mp[node]);

        return node;
    }
};