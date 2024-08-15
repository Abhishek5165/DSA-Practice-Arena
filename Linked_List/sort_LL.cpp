// Time Comeplexity : O(N+N/2) + O(LogN)
// Space Complexity : O(longN)

class Solution {
public: 
    ListNode* find(ListNode* head){

    if(head == NULL || head->next == NULL){
    return head;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
    }
    return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(left != NULL && right != NULL){
    
    if(left->val < right->val){
    temp->next = left;
    temp = temp->next;
    left = left->next;
    }
    else{
    temp->next = right;
    temp = temp->next;
    right = right->next;
    }
    }
    while(left){
    temp->next = left;
    temp = temp->next;
    left = left->next;
    }
    while(right){
    temp->next = right;
    temp = temp->next;
    right = right->next;
    }
    ListNode* farzi = dummy;
    temp = dummy->next;
    delete(dummy);
    return temp;
    }
    ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL){
    return head;
    }
    ListNode* middle = find(head);
    ListNode* left = head;
    ListNode* right = middle->next;
    middle->next = NULL;

    left = sortList(left);
    right = sortList(right);

    head = merge(left,right);
    return head;
    }
};