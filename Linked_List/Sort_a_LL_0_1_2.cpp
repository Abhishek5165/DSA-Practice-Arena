// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
    if(head == NULL || head->next == NULL){
    return head;
    }
    Node* zeroHead = new Node(1);
    Node* oneHead = new Node(1);
    Node* twoHead = new Node(1);
    
    Node* zero = zeroHead;
    Node* one  =  oneHead;
    Node* two  =  twoHead;
    
    Node* temp = head;
    
    while(temp != NULL){
        
    if(temp->data == 0){
    zero->next = temp;
    zero = zero->next;
    temp = temp->next;
    }
    else if(temp->data == 1){
    one->next = temp;
    one = one->next;
    temp = temp->next;
    }
    else{
    two->next = temp;
    two = two->next;
    temp = temp->next;
    }
    }
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    
    temp = zeroHead->next;
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);
    return temp;
    }
};