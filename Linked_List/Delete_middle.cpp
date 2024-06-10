// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
    if(head == NULL || head->next == NULL){
    return NULL;
    }   
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;

    while(fast != NULL && fast->next != NULL){

    fast = fast->next->next;
    prev = slow;
    slow = slow->next;
    }
    prev->next = slow->next;
    ListNode*temp = slow;
    slow->next = NULL;
    delete(temp);
    return head;
    }
};