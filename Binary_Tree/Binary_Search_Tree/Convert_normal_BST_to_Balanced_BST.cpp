// time complexity : O(N)
// space complexity : O(N)

class Solution {
public:

    void traversal(TreeNode* root,vector<int>&inorder){
    
    if(root == NULL){
    return;
    }
    traversal(root->left,inorder);
    inorder.push_back(root->val);
    traversal(root->right,inorder);
    }

    TreeNode* build(int left,int right,vector<int>&inorder){

    if(left > right) return NULL;
    
    int mid = left+(right-left)/2;
    TreeNode* root = new TreeNode(inorder[mid]);
    root->left = build(left,mid-1,inorder);
    root->right = build(mid+1,right,inorder);

    return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
    
    if(root == NULL){
        return root;
    }
    vector<int>inorder;
    traversal(root,inorder);
    int n = inorder.size();
    root = build(0,n-1,inorder);
    return root;
    }
};