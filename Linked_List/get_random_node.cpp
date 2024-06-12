// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    vector<int>ans;
    Solution(ListNode* head) {
    ListNode* temp = head;
    while(temp!=NULL){
    ans.push_back(temp->val);
    temp = temp->next;
    }
    }
    
    int getRandom() {
    int size = ans.size();
    int ran = rand()%size;

    return ans[ran];  
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)


class Solution {
public:
    ListNode* H;
    Solution(ListNode* head) {
     H = head;
    }
    
    int getRandom() {
    ListNode* temp = H;
    int count = 1;
    int result = 0;
    while(temp != NULL){
    
    if(rand()%count < 1.0/count){
    
    result = temp->val;
    }
    count++;
    temp = temp->next;
    } 
    return result;
    }
};