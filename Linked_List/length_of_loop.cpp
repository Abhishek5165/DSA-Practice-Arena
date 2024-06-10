// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

int countNodesinLoop(struct Node *head)
{
 if(head == NULL || head->next == NULL){
 return 0;
 }
 Node*slow = head;
 Node*fast = head;
 
 while(fast != NULL && fast->next != NULL){
     
 fast = fast->next->next;
 slow = slow->next;
 int count = 1;
 
 if(slow == fast){
    
 Node* temp = slow->next;
 while(temp != slow){
 count++;
 temp = temp->next;
 }
 return count;
 }
 }
 return 0;
}