// Approch - 1

class Solution {
public:
    int maxPath = 0;

    void solve(TreeNode* root,bool goLeft,int steps){

    if(root == NULL){
    return;
    }
    if(goLeft == true){
    solve(root->left,false,steps+1);
    solve(root->right,true,1);
    }
    else{

    solve(root->right,true,steps+1);
    solve(root->left,false,1);
    }
    maxPath = max(steps,maxPath);
    }

    int longestZigZag(TreeNode* root) {
    
    int steps = 0;
    bool goLeft;
    solve(root,goLeft,steps);
    return maxPath;
    }
};

// Approch - 2

// if go left send -> left as right+1 and wise versa

class Solution {
public:
    int maxPath = 0;

    void solve(TreeNode* root,int left,int right){

    if(root == NULL){
    return;
    }
    maxPath = max(maxPath,max(left,right));

    solve(root->left,right+1,0);
    solve(root->right,0,left+1);
    }

    int longestZigZag(TreeNode* root) {

    solve(root,0,0);
    return maxPath;   
    }
};