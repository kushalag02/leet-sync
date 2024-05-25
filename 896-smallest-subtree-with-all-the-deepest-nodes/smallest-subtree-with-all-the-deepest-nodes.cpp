class Solution {
public:
    void LeafVal(TreeNode* root, int depth, vector<TreeNode*>& leafNodes,
                 vector<int>& leafDepths) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            leafNodes.push_back(root);
            leafDepths.push_back(depth);
        }
        if (root->left) {
            LeafVal(root->left, depth + 1, leafNodes, leafDepths);
        }
        if (root->right) {
            LeafVal(root->right, depth + 1, leafNodes, leafDepths);
        }
    }
    TreeNode* findLCA(TreeNode* root, int depth, int maxDepth) {
        if (root == NULL)
            return NULL;
        if (depth == maxDepth)
            return root;

        TreeNode* left = findLCA(root->left, depth + 1, maxDepth);
        TreeNode* right = findLCA(root->right, depth + 1, maxDepth);

        if (left != NULL && right != NULL) {
            return root;
        } else if (left != NULL) {
            return left;
        } else {
            return right;
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> leafNodes;
        vector<int> leafDepths;
        LeafVal(root, 0, leafNodes, leafDepths);

        int maxDepth = *max_element(leafDepths.begin(), leafDepths.end());

        return findLCA(root, 0, maxDepth);
    }
};