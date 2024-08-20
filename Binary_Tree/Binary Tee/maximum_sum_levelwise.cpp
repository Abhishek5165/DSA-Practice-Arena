// time complxity : O(n);
// space complexity : O(n);

class Solution {

    int smallLevel = 0;
    int MaxSum = INT_MIN;

public:
    int maxLevelSum(TreeNode* root) {

        int level = 1;

        if (root == NULL) {
            return 0;
        }

        queue<TreeNode*> Q;
        Q.push(root);
        int sum;

        while (!Q.empty()) {

            int size = Q.size();

            sum = 0;

            while (size--) {

                auto it = Q.front();
                Q.pop();

                int value = it->val;
                sum += value;

                if (it->left != NULL) {
                    Q.push(it->left);
                }
                if (it->right != NULL) {
                    Q.push(it->right);
                }
            }
            if (sum > MaxSum) {
                smallLevel = level;
                MaxSum = sum;
            }
            level++;
        }
        return smallLevel;
    }
};