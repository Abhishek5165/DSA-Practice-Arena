// This problem is same as smallest subtree with the 

// 865. Smallest Subtree with all the Deepest Nodes

// time complexity : O(n);
// space complexity : O(n);

class Solution {
public:
    int height(TreeNode* root) {
        
        if (root == NULL) {
            return 0;
        }
        return (1 + max(height(root->left), height(root->right)));
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        if (root == NULL) {
            return root;
        }
        int left = height(root->left);
        int right = height(root->right);

        if (left == right) {
            return root;
        }
        if (left > right) {
            return lcaDeepestLeaves(root->left);
        } 
        else {
            return lcaDeepestLeaves(root->right);
        }
    }
};