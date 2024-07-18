// Time Complexity : O(N*N);
// Space Complexity : O(N);

class Solution {
public:
    void makeGraph(TreeNode* root, TreeNode* prev,
        unordered_map<TreeNode*, vector<TreeNode*>>& adj,
        unordered_set<TreeNode*>& st) {

        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            st.insert(root);
        }
        if (prev != NULL) {

            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }

    int countPairs(TreeNode* root, int distance) {

        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;

        makeGraph(root, NULL, adj, st);

        int count = 0;

        for (auto &leaf : st) {

            queue<TreeNode*> Q;
            unordered_set<TreeNode*> visited;

            Q.push(leaf);
            visited.insert(leaf);

            for (int level = 0; level <= distance; level++) {

                int size = Q.size();
                while (size--) {

                    TreeNode* temp = Q.front();
                    Q.pop();

                    if (temp != leaf && st.count(temp)) {
                        count++;
                    }
                    for (auto &ngbr : adj[temp]) {
                        
                        if (!visited.count(ngbr)) {
                            Q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
};