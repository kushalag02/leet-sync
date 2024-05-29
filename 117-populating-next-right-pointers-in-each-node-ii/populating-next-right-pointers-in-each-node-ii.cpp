class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return nullptr;

        vector<vector<Node*>> result = levelOrder(root);
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size() - 1; j++) {
                result[i][j]->next = result[i][j + 1];
            }
        }
        return root;
    }

    vector<vector<Node*>> levelOrder(Node* root) {
        vector<vector<Node*>> result;
        if (root == NULL)
            return result;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<Node*> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                level.push_back(node);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
};