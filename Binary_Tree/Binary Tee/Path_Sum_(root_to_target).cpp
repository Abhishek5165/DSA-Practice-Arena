// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

    if(root == NULL){
        return false;
    } 
    if(root->left == 0 && root->right == 0) return targetSum == root->val;

    bool option1 = hasPathSum(root->left,targetSum-root->val);
    bool option2 = hasPathSum(root->right,targetSum-root->val);

    return (option1 || option2);
    }
};