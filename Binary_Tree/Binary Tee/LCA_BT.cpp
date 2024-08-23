// Using Recursion .....

// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root->val == p->val || root->val == q->val) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        } else {
            return root;
        }
    }
};