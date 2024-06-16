// time complexity : O(n)
// space complexity : O(1)

class Solution {
public:
    Node* connect(Node* root) {

    if(root == NULL){
    return NULL;
    }
    Node* curr = root;
    while(curr != NULL){

    Node* dummy = new Node();
    Node* temp = dummy;

    while(curr!=NULL){

    if(curr->left != NULL){
    temp->next = curr->left;
    temp = temp->next;
    }
    if(curr->right != NULL){
    temp->next = curr->right;
    temp = temp->next;
    }
    curr = curr->next;
    }
    curr = dummy->next;
    }
    return root;
    }
};


// Now Using Approch - 2 Using Queue.

// time complexity : O(n)
// space complexity : O(n)


class Solution {
public:
    Node* connect(Node* root) {

    if(root == NULL){
    return NULL;
    } 
    queue<Node*>Q;
    Q.push(root);

    while(!Q.empty()){

    Node* prev = NULL;
    int size = Q.size();
    
    for(int i=0;i<size;i++){

    Node* top = Q.front();
    Q.pop();

    top->next = prev;
    prev = top;

    if(top->right != NULL){
    Q.push(top->right);
    }
    if(top->left != NULL){
    Q.push(top->left);
    }
    }
    }
    return root;
    }
};