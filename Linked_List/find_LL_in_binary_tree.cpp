// Time complexity: (2^N)
// Space complexity: O(h)

class Solution {
public:
    
    bool found(ListNode* head,TreeNode* root){

    if(root == NULL){
    return false;
    }
    if(match(head,root)){
    return true;
    }
    return found(head,root->left) || found(head,root->right);
    }

    bool match(ListNode* head,TreeNode* root){

    if(head == NULL){
    return true;
    }
    if(root == NULL || root->val != head->val){
    return false;
    }
    return match(head->next,root->left) ||
                match(head->next,root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
    return found(head,root);  
    }
};