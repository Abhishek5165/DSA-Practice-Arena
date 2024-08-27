// Expected Time Complexity: O(Height of the BST)
// Expected Auxiliary Space: O(1).

class Solution {
  public:
    int minValue(Node* root) {
     if(root == NULL || root->left == NULL){
     return root->data;
     }
     while(root != NULL && root->left != NULL){
     root = root->left;
     }
     return root->data;
    }
};