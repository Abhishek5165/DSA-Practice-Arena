// Time Complexity : O(logK*N);
// Space Complexity : O(LogK);

class Solution {
public:
    
    ListNode* merge(ListNode* &L1,ListNode* &L2){
    
    if(L1 == NULL){
    return L2;
    }
    if(L2 == NULL){
    return L1;
    }
    if(L1->val <= L2->val){
    L1->next = merge(L1->next,L2);
    return L1;
    }
    else{
    L2->next = merge(L1,L2->next);
    return L2;
    }
    return NULL;
    }
    ListNode* solve(int start,int end,vector<ListNode*>& lists){
    
    if(start > end){
    return NULL;
    }
    if(start == end){
    return lists[start];
    }
    int mid = start + (end-start)/2;
    
    ListNode* L1 = solve(start,mid,lists);
    ListNode* L2 = solve(mid+1,end,lists);

    return merge(L1,L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    if(k <= 0){
    return NULL;
    }
    return solve(0,k-1,lists);  
    }
};
