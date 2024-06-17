// Time complexity : O(n)
// Space complexity : O(h)

class Solution {
public:
    int solve(TreeNode* &node,int val){

    if(node == NULL){
    return 0;
    }
    int count = 0;

    if(node->val >= val){
    count = 1;
    val = node->val;
    }
    count += solve(node->left,val);
    count += solve(node->right,val);

    return count;
    }

    int goodNodes(TreeNode* root) {
    return solve(root,root->val);
    }
};