// Time Complexity : O(NLogN);
// Space Complexity : O(N);

class Solution{
  public:

    void In(Node* root,vector<int>&inorder){
        
    if(root == NULL){
    return;
    }
    In(root->left,inorder);
    inorder.push_back(root->data);
    In(root->right,inorder);
    }
    
    
    void build(Node* root,vector<int>&inorder,int &i){
    
    if(root == NULL){
    return;
    }
    build(root->left,inorder,i);
    root->data = inorder[i];
    i++;
    build(root->right,inorder,i);
    }


    Node *binaryTreeToBST (Node *root)
    {
    vector<int>inorder;
    In(root,inorder);
    
    sort(inorder.begin(),inorder.end());
    int i=0;
    build(root,inorder,i);
    return root;
    }
};
