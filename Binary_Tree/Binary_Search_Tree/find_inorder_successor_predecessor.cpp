// Time Complexity : O(H) + O(H);
// Space Complexity : O(1);

class Solution{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
        
    pre = NULL;
    suc = NULL;
    Node* temp1 = root;
    
    while(temp1){
    if(temp1->key <= key){
    temp1 = temp1->right;
    }
    else{
    suc = temp1;
    temp1 = temp1->left;
    }
    }
    
    Node* temp2 = root;
    
    while(temp2){
  
    if(temp2->key >= key){
    temp2 = temp2->left;
    }
    else{
    pre = temp2;
    temp2 = temp2->right;
    }
    }
    }
};