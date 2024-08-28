// Time Complexity : O(N);
// Space Complexity : O(H);

class Solution {

TreeNode* first;
TreeNode* prev = NULL;
TreeNode* middle;
TreeNode* last;

public:
    void solve(TreeNode* root){

    if(root == NULL){
    return;
    }
    solve(root->left);
    if(prev != NULL && root->val < prev->val){
    
    if(first == NULL){
    first = prev;
    middle = root;
    }
    else{
    last = root;
    }
    }
    prev = root;
    solve(root->right);
    }
    void recoverTree(TreeNode* root){
    if(root == NULL){
    return;
    }
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);

    solve(root);

    if(first && last){
    swap(first->val,last->val);
    }
    else if(first && middle){
    swap(first->val,middle->val);
    }
    }
};