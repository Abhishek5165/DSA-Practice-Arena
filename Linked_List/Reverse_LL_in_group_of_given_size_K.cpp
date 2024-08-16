// Time Complexity : O(2*N);
// Space Complexity : O(1);

class Solution {
public:
    ListNode* find(ListNode* temp,int k){
    k = k-1;
    while(temp != NULL && k>0){
    k--;
    temp = temp->next;
    }
    return temp;
    }

    ListNode* reverse(ListNode * &head){
    if(head == NULL || head->next == NULL){
    return head;
    }
    ListNode* forward = head;
    ListNode* curr = head;
    ListNode* prev = NULL;

    while(curr != NULL){
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    }
    return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || head->next == NULL){
    return head;
    }
    ListNode* temp = head;
    ListNode* prev = NULL;
    ListNode* nextNode = NULL;
    while(temp != NULL){

    ListNode* kthNode = find(temp,k);

    if(kthNode == NULL){
    if(prev != NULL){
    prev->next = temp;
    break;
    }
    }
    else{
    nextNode = kthNode->next;
    kthNode->next = NULL;
    reverse(temp);

    if(head == temp){
    head = kthNode;
    }
    else{
    prev->next = kthNode;
    }
    }
    prev = temp;
    temp = nextNode;
    }
    return head;
    }
};