// overall time complexity : O(n)
// space complexity : O(n)

class Solution {

public:
    void mark_parent(unordered_map<TreeNode*, TreeNode*>& parent,
                     TreeNode* root) {

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {

            TreeNode* temp = Q.front();
            Q.pop();

            if (temp->left) {
                parent[temp->left] = temp;
                Q.push(temp->left);
            }
            if (temp->right) {
                parent[temp->right] = temp;
                Q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;

        mark_parent(parent, root);

        queue<TreeNode*> Q;
        Q.push(target);
        visited[target] = true;

        int dis = 0;

        while (!Q.empty()) {

            int size = Q.size();

            if (dis++ == k)
                break;

            for (int i = 0; i < size; i++) {

                TreeNode* temp = Q.front();
                Q.pop();

                if (temp->left && !visited[temp->left]) {

                    visited[temp->left] = true;
                    Q.push(temp->left);
                }
                if (temp->right && !visited[temp->right]) {

                    visited[temp->right] = true;
                    Q.push(temp->right);
                }
                if (parent[temp] && !visited[parent[temp]]) {

                    visited[parent[temp]] = true;
                    Q.push(parent[temp]);
                }
            }
        }
        vector<int> ans;

        while (!Q.empty()) {

            TreeNode* temp = Q.front();
            Q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};