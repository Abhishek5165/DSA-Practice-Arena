// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if(root == NULL){
    return NULL;
    }  
    TreeNode* temp = new TreeNode(root->val);
    temp->right = invertTree(root->left);
    temp->left = invertTree(root->right);

    return temp;
    }
};
