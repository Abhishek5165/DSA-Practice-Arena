// Time Complexity : O(n);
// Space Complexity : O(1);

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

    while(head != NULL && head->val == val){
    ListNode* temp = head;
    head = head->next;
    delete(temp);
    }

    ListNode* temp = head;

    while(temp != NULL && temp->next != NULL){
    if(temp->next->val == val){
    ListNode* farzi = temp->next;
    temp->next = temp->next->next;
    delete(farzi);
    }
    else{
    temp = temp->next;
    }
    }
    return head;
    }
};