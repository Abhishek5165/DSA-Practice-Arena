// Time Complexity: O(N+M).
// Space Complexity: O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL){
    return true;
    }
    if(p == NULL || q == NULL){
    return false;
    }
    return ((p->val == q->val) && isSameTree(p->left,q->left) && 
    isSameTree(p->right,q->right));
    }
};
