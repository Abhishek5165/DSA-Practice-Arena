// Time complexity : O(N)
// Space complexity : O(h)

class Solution {
public:
    int solve(TreeNode* &root,int &moves){

    if(root == NULL){
    return 0;
    } 
    int left = solve(root->left,moves);
    int right = solve(root->right,moves);

    moves += abs(left) + abs(right);
    
    return (left+right+root->val) - 1;
    }

    int distributeCoins(TreeNode* root) {

    int moves = 0;
    solve(root,moves);
    return moves;
    }
};