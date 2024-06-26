// time complexity : O(n);
// space complexity : O(n);

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        if (root1 == root2) {
            return true;
        }
        if ((root1 == NULL || root2 == NULL) 
        || (root1->val != root2->val)) {
            return false;
        }

        bool one = flipEquiv(root1->left, root2->left) &&
                   flipEquiv(root1->right, root2->right);

        bool two = flipEquiv(root1->left, root2->right) &&
                   flipEquiv(root1->right, root2->left);

        return (one || two);
    }
};