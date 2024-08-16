// Time Complexity : O(m*N*N);
// Space Complexity : O(N*N);

// here N = total number of nodes;
// m is the height of the linked list in the direction of down.

class Solution {
  public:
  
    Node* merge(Node* root,Node* head){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    
    while(head != NULL && root != NULL){
    
    if(root->data < head->data){
    temp->bottom = root;
    temp = temp->bottom;
    root = root->bottom;
    }
    else{
    temp->bottom = head;
    temp = temp->bottom;
    head = head->bottom;
    }
    }
    while(root != NULL){
    temp->bottom = root;
    temp = temp->bottom;
    root = root->bottom;
    }
    while(head != NULL){
    temp->bottom = head;
    temp = temp->bottom;
    head = head->bottom;
    }
    temp = dummy->bottom;
    Node* farzi = dummy;
    delete(dummy);
    return temp;
    }
    
    Node *flatten(Node *root) {
    if(root == NULL){
    return NULL;
    }
    Node* head = flatten(root->next);
    return merge(root,head);
    }
};
