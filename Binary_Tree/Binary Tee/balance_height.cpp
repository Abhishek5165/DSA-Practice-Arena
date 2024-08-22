// Brute Force .....

// Time Complexity : O(n*n);
// Space Complexity : O(H);

class Solution {
public:
    int solve(TreeNode* root){
    if(root == NULL){
    return 0;
    }
    int Left = solve(root->left);
    int Right = solve(root->right);
    
    return 1 + max(Left,Right);
    }
    bool isBalanced(TreeNode* root) {
    if(root == NULL){
    return true;
    }
    int leftH = solve(root->left);
    int rightH = solve(root->right);

    if(abs(leftH-rightH) <= 1 && isBalanced(root->left) 
    && isBalanced(root->right)){
    return true;
    }
    return false;
    }
};


// Time Complexity: O(N);
// Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space.


class Solution {
public:
    int solve(TreeNode* root){
    if(root == NULL){
    return 0;
    }
    int LeftH = solve(root->left);
    if(LeftH == -1){
    return -1;
    }
    int RightH = solve(root->right);
    if(RightH == -1){
    return -1;
    }
    if(abs(RightH-LeftH) > 1){
    return -1;
    }
    return 1 + max(RightH,LeftH);
    }
    bool isBalanced(TreeNode* root) {
    return solve(root) != -1;   
    }
};
