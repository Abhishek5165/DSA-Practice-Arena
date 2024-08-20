class Solution {

    int H;

public:
    int height(TreeNode* node) {

        if (node == NULL) {
            return 0;
        }
        int leftH = 1 + height(node->left);
        int rightH = 1 + height(node->right);

        return (leftH > rightH) ? leftH : rightH;
    }

    void solve(TreeNode* root, vector<vector<string>>& ans,
    int row, int col) {

        if (root == NULL) {
            return;
        }
        ans[row][col] = to_string(root->val);

        solve(root->left, ans, row + 1, col - (pow(2, H - row - 1)));
        solve(root->right, ans, row + 1, col + (pow(2, H - row - 1)));
    }

    vector<vector<string>> printTree(TreeNode* root) {

        H = height(root) - 1;

        int rows = H + 1;
        int columns = pow(2, H + 1) - 1;

        vector<vector<string>> ans(rows, vector<string>(columns, ""));

        solve(root, ans, 0, (columns - 1) / 2);

        return ans;
    }
};