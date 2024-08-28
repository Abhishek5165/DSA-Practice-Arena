// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, 
    TreeNode* p, TreeNode* q) {
    while(true){
    
    if(root->val < p->val && root->val < q->val){
    root = root->right;
    }
    else if(root->val > p->val && root->val > q->val){
    root = root->left;
    }
    else{
    return root;
    }
    }
    }
};