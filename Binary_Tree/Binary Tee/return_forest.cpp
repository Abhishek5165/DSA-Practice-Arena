// time complexity : O(n);
// space complexity : O(n);


class Solution {
public:
    TreeNode* solve(TreeNode*& root, unordered_set<int>& st,
                    vector<TreeNode*>& ans) {

        if (root == NULL) {
            return NULL;
        }
        root->left = solve(root->left, st, ans);
        root->right = solve(root->right, st, ans);

        if (st.find(root->val) != st.end()) {

            if (root->left != NULL) {
                ans.push_back(root->left);
            }
            if (root->right != NULL) {
                ans.push_back(root->right);
            }
            return NULL;
        } 
        else {
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        vector<TreeNode*> ans;
        unordered_set<int> st;

        for (auto it : to_delete) {
            st.insert(it);
        }
        solve(root, st, ans);

        if ((st.find(root->val)) == st.end()) {
            ans.push_back(root);
        }
        return ans;
    }
};