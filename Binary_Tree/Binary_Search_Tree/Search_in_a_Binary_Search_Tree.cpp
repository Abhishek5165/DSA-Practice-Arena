// Time Complexity: O(logN) on average for a balanced BST, and 
// O(N) in the worst case (skewed tree).

// Space Complexity: O(logN) on average for a balanced BST due to recursion stack depth, and O(N) in the worst case (skewed tree).

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

    if(root == NULL || root->val == val){
    return root;
    }  
    if(val > root->val){
    return searchBST(root->right,val);
    }
    else{
    return searchBST(root->left,val);
    }
    }
};