class Codec {
public:
    string serialize(TreeNode* root) {
        string ans = "";
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL)
                ans += "$,";
            else {
                ans += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            }
        }
        if (!ans.empty() && ans.back() == ',')
            ans.pop_back();
        return ans;
    }
    TreeNode* deserialize(string nums) {
        if (nums.empty() == true)
            return NULL;

        stringstream ss(nums);
        string val;
        getline(ss, val, ',');

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (getline(ss, val, ',')) {
                if (val == "$") {
                    node->left = nullptr;
                } else {
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }
            if (getline(ss, val, ',')) {
                if (val == "$") {
                    node->right = nullptr;
                } else {
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));