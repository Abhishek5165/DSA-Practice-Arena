class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* current = head;
    ListNode* f = head;
    ListNode* prev = NULL;

while(current!=NULL){
    f = current->next;
    current->next = prev;
    prev = current;
    current = f;
}
head = prev;
return head;
}
};