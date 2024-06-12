// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
    ListNode* dummy = new ListNode(100);
    ListNode* real = dummy;

    ListNode* temp = head->next;
    int sum = 0;
    while(temp != NULL){

    if(temp->val == 0){
    ListNode* newNode = new ListNode(sum);
    real->next = newNode;
    real = newNode;
    sum = 0;
    }
    else{
    sum += temp->val;
    }
    temp = temp->next;
    }
    head = dummy->next;
    delete(dummy);
    return head;
    }
};