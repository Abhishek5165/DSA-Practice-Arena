// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

     if(head == NULL || head->next == NULL){
     return NULL;
     }
     ListNode* fast = head;
     ListNode* slow = head;
     ListNode* temp = head;

     while(fast != NULL && fast->next != NULL){

     fast = fast->next->next;
     slow = slow->next;

     if(slow == fast){
     
     while(temp != slow){
     slow = slow->next;
     temp = temp->next;
     }
     return slow;
     }
     }
     return NULL;
    }
};