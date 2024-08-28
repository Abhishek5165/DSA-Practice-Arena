// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    TreeNode* build(int &i,vector<int>&preorder,int bound){
    if(i == preorder.size() || preorder[i] > bound){
    return NULL;
    }
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = build(i,preorder,root->val);
    root->right = build(i,preorder,bound);

    return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    int bound = INT_MAX;
    return build(i,preorder,bound);
    }
};