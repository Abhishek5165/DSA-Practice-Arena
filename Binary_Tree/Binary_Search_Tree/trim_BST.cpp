// Time Complexity: O(N) where N is the number of nodes in the BST.
// Space Complexity: O(N) in the worst case due to recursive stack usage.

class Solution {
public:
    TreeNode* trim(TreeNode* &root, int low, int high) {

    if(root == NULL){
    return NULL;
    } 
    TreeNode* left = trim(root->left,low,high);
    TreeNode* right = trim(root->right,low,high);

    if(left != root->left){
    root->left = left;
    }
    if(right != root->right){
    root->right = right;
    }

    if(root->val > high || root->val < low){
    return (root->left) ? root->left : root->right;
    } 
    return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
    return trim(root,low,high);   
    }
};