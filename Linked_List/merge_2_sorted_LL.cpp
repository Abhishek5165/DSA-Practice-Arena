// Iterative Solution -----------------------

// Time Complexity : O(n+m)
// Auxilliary Space : O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    ListNode* dummy = new ListNode();
    ListNode* temp = dummy;

    while(list1 != NULL && list2 != NULL){
    
    if(list1->val < list2 ->val){

    temp->next = list1;
    temp = temp->next;
    list1 = list1->next;
    }
    else{

    temp->next = list2;
    temp = temp->next;
    list2 = list2->next;
    }
    }
    while(list1 != NULL){

    temp->next = list1;
    temp = temp->next;
    list1 = list1->next;
    }
    while(list2 != NULL){

    temp->next = list2;
    temp = temp->next;
    list2 = list2->next;
    }
    return dummy->next;
    }
};


// Approch - 2 Using Recurtion ---------------------------------------

// Time Complexity : O(n+m)
// Auxilliary Space : O(n+m)

 Node* sortedMerge(Node* head1, Node* head2)  
{  
 if(head1 == NULL){
 return head2;
 }
 if(head2 == NULL){
 return head1;
 }
 
 Node* result;
     
 if(head1->data < head2->data){
     
 result = head1;
 result->next = sortedMerge(head1->next,head2);
 }
 else{
     
 result = head2;
 result->next = sortedMerge(head2->next,head1);
 }
 return result;
}  