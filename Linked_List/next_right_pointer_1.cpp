// time complexity : O(n)
// space complexity : O(1)

class Solution {
public:
    Node* connect(Node* root) {

    if(root == NULL){
    return NULL;
    } 
    Node* curr = root;
    while(curr->left != NULL){

    Node* temp = curr->left;
    while(curr != NULL){

    curr->left->next = curr->right;
    if(curr->next != NULL){
    curr->right->next = curr->next->left;
    }
    else{
    curr->right->next = NULL;
    }
    curr = curr->next;
    }
    curr = temp;
    }
    return root;
    }
};