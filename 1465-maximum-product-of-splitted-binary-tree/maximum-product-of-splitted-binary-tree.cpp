class Solution {
public:
    long long dfs(TreeNode* node, long long total, long long& maxi) {
        if (!node) return 0;
        
        long long left = dfs(node->left, total, maxi);
        long long right = dfs(node->right, total, maxi);
        
        long long subSum = left + right + node->val;
        long long product = subSum * (total - subSum);
        maxi = max(maxi, product);
        
        return subSum;
    }
    
    int maxProduct(TreeNode* root) {
        long long total = solve(root);
        long long maxi = 0;
        dfs(root, total, maxi);
        return maxi % 1000000007;
    }
    
    long long solve(TreeNode* node) {
        if (!node) return 0;
        return node->val + solve(node->left) + solve(node->right);
    }
};
