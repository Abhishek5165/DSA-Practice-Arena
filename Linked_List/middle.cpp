class Solution {
public:
    ListNode* middleNode(ListNode* head) {

    if(head == NULL || head->next == NULL){
    return head;
    }    

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){

    fast = fast->next->next;
    slow = slow->next;
    }
    return slow;
    }
};


// Another Way 


class Solution {
public:
ListNode* middleNode(ListNode* head) {

ListNode* temp = head;
 int i=0;

while(head != NULL){

if(i%2 == 1){
temp = temp->next;
}
head = head->next;
i++;
}
return temp;
}
};


// using Recursion ....


class Solution {
public:
    ListNode* solve(ListNode* slow,ListNode* fast){
    
    if(fast->next == NULL){
    return slow;
    }
    if(fast->next->next == NULL){
    return slow->next;
    }
    return solve(slow->next,fast->next->next);
    }
    ListNode* middleNode(ListNode* head) {
    return solve(head,head);
    }
};

// This will give the just previous element of the middle ...

class Solution {
public:
    ListNode* solve(ListNode* slow, ListNode* fast) {
        if (fast == NULL || fast->next == NULL) {
            return slow;
        }
        return solve(slow->next, fast->next->next);
    }

    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        return solve(head, head);
    }
};
