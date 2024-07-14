// Time complexity : O(n);
// Space complexity : O(n);

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        int n = nums.size();
        if (head == NULL || n == 0) {
            return head;
        }
        unordered_set<int>mpp(nums.begin(),nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* temp = head;

        while (temp != NULL) {

            if (mpp.find(temp->val) != mpp.end()) {

                prev->next = temp->next;
                delete (temp);
                temp = prev->next;
            } 
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        ListNode* result = dummy->next;
        delete dummy; 
        return result;
    }
};