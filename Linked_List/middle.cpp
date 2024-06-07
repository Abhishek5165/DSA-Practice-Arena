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