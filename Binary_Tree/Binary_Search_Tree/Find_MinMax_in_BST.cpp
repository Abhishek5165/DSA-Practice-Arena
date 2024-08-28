// Expected Time Complexity: O(Height of the BST)
// Expected Auxiliary Space: O(1).

// Find Min Value in BST ..

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

// Find Max Value in BST ..

class Solution {
  public:
    int maxValue(Node* root) {
     if(root == NULL || root->right == NULL){
     return root->data;
     }
     while(root != NULL && root->right != NULL){
     root = root->right;
     }
     return root->data;
    }
};