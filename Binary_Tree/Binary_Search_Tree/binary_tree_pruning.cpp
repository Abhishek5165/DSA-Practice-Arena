// Time Complexity: O(N*N) where N is the number of nodes in the BST.
// Space Complexity: O(N) in the worst case due to recursive stack usage.

// Approch - 1 

class Solution {
public:
    bool isOne(TreeNode* node){
    if(node == NULL){
    return false;
    }
    if(node->val == 1){
    return true;
    }
    return (isOne(node->left) || isOne(node->right));
    }

    TreeNode* pruneTree(TreeNode* root) {

    if(root == NULL){
    return NULL;
    }

    if(!isOne(root->left)){
    root->left = NULL;
    } 
    if(!isOne(root->right)){
    root->right = NULL;
    }
    pruneTree(root->left);
    pruneTree(root->right);

    if(root->left == NULL && root->right == NULL
     && root->val == 0){
     return NULL;
     }
     return root;
    }
};


// Approch - 2 

// Time Complexity: O(N)
// Space Complexity: O(N)


class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {

    if(root == NULL){
    return root;
    }  
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    if(root->left == NULL && root->right == NULL && root->val == 0){
    return NULL;
    }
    return root;
    }
};