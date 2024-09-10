// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
    if(head == NULL || head->next == NULL){
    return head;
    } 
    ListNode* temp = head;

    while(temp->next != NULL){

    int gcd = __gcd(temp->val,temp->next->val);
    ListNode* newNode = new ListNode(gcd,temp->next);
    temp->next = newNode;
    temp = newNode->next;
    }
    return head;
    }
};