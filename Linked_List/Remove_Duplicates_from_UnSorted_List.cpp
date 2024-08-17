// Time Complexity : O(n);
// Space Complexity : O(n);

Node * removeDuplicates( Node *head){

    if(head == NULL || head->next == NULL){
    return head;
    }
    
    set<int> st;
    Node* curr = head;
    Node* prev = NULL;
    while(curr) {
        if(!st.count(curr->data)) {
            st.insert(curr->data);
            prev = curr;
            curr = curr->next;
        } 
        else {
            prev->next = curr->next;
            delete(curr);
            curr = prev->next;
        }
    }
    return head;
}