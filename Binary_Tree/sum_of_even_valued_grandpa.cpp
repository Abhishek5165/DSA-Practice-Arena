// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    void solve(TreeNode* &root,int &ans){

    if(root == NULL){
    return;
    }
    if(root->val%2 == 0){

    if(root->left){
    if(root->left->left != NULL){
    ans += root->left->left->val;
    }
    if(root->left->right != NULL){
    ans += root->left->right->val;
    }
    }
    
    if(root->right){
    if(root->right->left != NULL){
    ans += root->right->left->val;
    }
    if(root->right->right != NULL){
    ans += root->right->right->val;
    }
    }
    }
    solve(root->left,ans);
    solve(root->right,ans);
    }
    int sumEvenGrandparent(TreeNode* root) {

    int ans = 0;
    solve(root,ans);
    return ans;
    }
};

// Approch - 2 

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int sum=0;
    void helper(TreeNode* root,TreeNode* parent,TreeNode* gp){

        if(root==NULL)return;

        if(gp && gp->val%2==0)sum+=root->val;

        helper(root->left,root,parent);
        helper(root->right,root,parent);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)return 0;
        helper(root,NULL,NULL);
        return sum;
    }
};