// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:

    void Inorder(TreeNode* root,int &count){
    if(root==NULL){
        return;
    }
    Inorder(root->left,count);
    count++;
    Inorder(root->right,count);

    }

    int countNodes(TreeNode* root) {
    
    int count = 0;
    Inorder(root,count);
    return count;
    }
};


// Optimize ......

// counting Left & Right Nodes.

// Time complexity : O(LogN * LogN)
// Time complexity : O(LogN) why LogN because height of complete BT is LogN


class Solution {
public:
    int solveLeft(TreeNode* root){
    int high = 0;
    while(root){
        high++;
    root = root->left;
    }
    return high;
    }
    int solveRight(TreeNode* root){
    int high = 0;
    while(root){
        high++;
    root = root->right;
    }
    return high;
    }

    int countNodes(TreeNode* root) {
    if(root == NULL){
    return 0;
    }
    int H1 = solveLeft(root);
    int H2 = solveRight(root);

    if(H1 == H2){
    return ((1 << H1) - 1);
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
    }
};