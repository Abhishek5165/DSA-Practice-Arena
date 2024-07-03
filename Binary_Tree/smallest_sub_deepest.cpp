// 865. Smallest Subtree with all the Deepest Nodes

// time complexity : O(n);
// space complexity : O(n);

class Solution {
public:
    
    int height(TreeNode* root){

    if(root == NULL){
    return 0;
    }
    return (1 + max(height(root->left),height(root->right)));
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

    if(root==NULL){
    return root;
    } 
    int left = height(root->left);
    int right = height(root->right);

    if(left == right){
    return root;
    }
    if(left > right){
        return subtreeWithAllDeepest(root->left);
    }
    else{
        return subtreeWithAllDeepest(root->right);
    }
    }
};