// Time Complexity : O(n+m)
// Space Complexity : O(1)

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, 
    int b, ListNode* list2) {
        
    ListNode* temp1 = NULL;
    ListNode* temp2 = list1;

    for(int i=0;i<=b;i++){

    if(i == a-1){
    temp1 = temp2;
    }
    temp2 = temp2->next;
    }
    temp1->next = list2;
    ListNode* temp = list2;

    while(temp->next != NULL){
    temp = temp->next;
    }
    temp->next = temp2;
    return list1;
    }
};