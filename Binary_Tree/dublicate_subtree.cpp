// Time complexity : O(n*n)
// Space complexity : O(n)

class Solution {
public:
    string solve(TreeNode*& root, unordered_map<string, int>& mpp,
                 vector<TreeNode*>& res) {

        if (root == NULL) {
            return "N";
        }

        string s = to_string(root->val) + "," + 
        solve(root->left, mpp, res) + ',' + 
        solve(root->right, mpp, res);

        if (mpp[s] == 1) {
            res.push_back(root);
        }
        mpp[s]++;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        vector<TreeNode*> res;
        unordered_map<string, int> mpp;

        solve(root, mpp, res);

        return res;
    }
};