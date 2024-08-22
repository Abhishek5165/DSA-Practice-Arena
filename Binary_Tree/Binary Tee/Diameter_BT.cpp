// Brute Force Approach....

// Time Complexity: O(N*N) where N is the number of nodes in the Binary Tree.

// Space Complexity : O(1) as no additional data structures or memory is allocated.O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.


class Solution {
public:
    int dia = 0;
    int height(TreeNode* root){
    if(root == NULL){
    return 0;
    }
    int Left = height(root->left);
    int Right = height(root->right);
    dia = max(dia,Left+Right);
    return (1 + max(Left,Right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
    height(root);
    return dia;   
    }
};




// Optimize ....

// Time Complexity: O(N)...
// Space Complexity: O(N) recursion stack space..

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
    int dia = 0;
    height(root,dia);
    return dia;   
    }
    int height(TreeNode* root,int &dia){
    if(root == NULL){
    return 0;
    }
    int Left = height(root->left,dia);
    int Right = height(root->right,dia);
    dia = max(dia,Left+Right);
    return (1 + max(Left,Right));
    }
};
