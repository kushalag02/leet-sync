class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;

        if (search(root, key) != NULL) {
            root = solve(root, key);
        }

        return root;
    }

    TreeNode* search(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key)
            return root;
        if (root->val < key) {
            return search(root->right, key);
        } else {
            return search(root->left, key);
        }
    }

    TreeNode* solve(TreeNode* root, int key) {
        if (root == NULL)
            return root;

        if (key < root->val) {
            root->left = solve(root->left, key);
        } else if (key > root->val) {
            root->right = solve(root->right, key);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* temp = mini(root->right);
            root->val = temp->val;
            root->right = solve(root->right, temp->val);
        }
        return root;
    }

    TreeNode* mini(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }
};
