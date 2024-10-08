// Time Complexity : O(n);
// Space Complexity : O(1);


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        if(head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        ListNode* temp = head->next;
        while(temp && temp->val == head->val)
            temp = temp->next;
        return deleteDuplicates(temp);
        
    }
};