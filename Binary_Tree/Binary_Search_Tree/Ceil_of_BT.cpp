// Time Complexity: O(log2N) 
// Space Complexity : O(1)

#include <bits/stdc++.h> 
int findCeil(BinaryTreeNode<int> *node, int x){
  int ceil = -1;
  while(node != NULL){
    if(x == node->data){
    ceil = node->data;
    }
    if(x > node->data){
    node = node->right;
    }
    else{
    ceil = node->data;
    node = node->left;
    }
  }
  return ceil;
}