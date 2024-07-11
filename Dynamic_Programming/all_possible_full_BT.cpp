// Time complexity : O(2^n);
// Space complexity : O(2^n);

class Solution {
public:
    vector<TreeNode*> solve(int n) {

        unordered_map<int,vector<TreeNode*>>mpp;

        if (!(n & 1)) {
            return {};
        }
        if (n == 1) {
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        if(mpp.find(n) != mpp.end()){
        return mpp[n];
        }

        vector<TreeNode*> result;

        for (int i = 1; i < n; i += 2) {

            vector<TreeNode*> Left = solve(i);
            vector<TreeNode*> Right = solve(n - i - 1);

            for (auto& L : Left) {

                for (auto& R : Right) {

                    TreeNode* newNode = new TreeNode(0);

                    newNode->left = L;
                    newNode->right = R;

                    result.push_back(newNode);
                }
            }
        }
        return mpp[n] = result;
    }

    vector<TreeNode*> allPossibleFBT(int n) { return solve(n); }
};