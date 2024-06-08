
// Using the map 
// Time Complexity: O(N * 2 * log(N))
// Space Complexity : O(N)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
    unordered_map<ListNode*,int>mpp;
    ListNode* temp = head;

    while(temp != NULL){

    if(mpp.find(temp) != mpp.end()){
    return true;
    }
    mpp[temp] = 1;
    temp = temp->next;
    }
    return false;
    }
};


// Approch - 2 

// Time Complexity: O(N)
// Space Complexity : O(1)


class Solution {
public:
    bool hasCycle(ListNode *head) {

    if(head == NULL || head->next == NULL){
    return false;
    } 
    
    ListNode*fast = head;
    ListNode*slow = head;

    ListNode* temp = head;
    while(fast != NULL && fast->next != NULL){

    fast = fast->next->next;
    slow = slow->next;

    if(slow == fast){
    return true;
    break;
    }
    }
    return false;
    }
};