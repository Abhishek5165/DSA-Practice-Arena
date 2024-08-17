// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL || head->next == NULL){
        return head;
        }
        ListNode* curr = head;
        ListNode *temp = NULL;

        while(curr != NULL && curr->next != NULL) {
            if(curr->val == curr->next->val) {
                temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            } 
            else{
            curr = curr->next;
            }
        }
        return head;
    }
};