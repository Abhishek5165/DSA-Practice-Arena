// Time Complexity: O(N).
// Auxiliary Space: O(1).

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


// using Recursion ---------------------

//  Time Complexity: O(N).
//  Auxiliary Space: O(N).

class Solution
{
    public:
    
    struct Node* reverseList(struct Node *head)
    {
     if(head == NULL || head->next == NULL){
     return head;
     }
     Node*temp = reverseList(head->next);
     head->next->next = head;
     head->next = NULL;
     
     return temp;
    }
};
