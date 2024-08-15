// Solution: Brute Force
// Time Complexity: O(Number of nodes present in the list*k);
// Space complexity : O(1);

node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}


// Time Complexity: O(length of list) + O(length of list - (length of list%k))
// Space Complexity: O(1);


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL){
    return head;
    } 
    int count = 1;
    ListNode* temp = head;
    while(temp->next != NULL){
    count++;
    temp = temp->next;
    }
    temp->next = head;
    k = k%count;
    int end = count-k;

    while(end--) temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
    }
};