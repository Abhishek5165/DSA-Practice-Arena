// Time Complexity : O(n);
// Time Complexity : O(1);

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    if(head == NULL || head->next == NULL){
    return head;
    }
    ListNode* dummy = new ListNode(0);

    while(head != NULL){
    ListNode* nextNode = head->next;
    ListNode* temp = dummy;

    while(temp->next && temp->next->val < head->val){
    temp = temp->next;
    }
    head->next = temp->next;
    temp->next = head;
    head = nextNode;
    }
    head = dummy->next;
    delete(dummy);
    return head;
    }
};