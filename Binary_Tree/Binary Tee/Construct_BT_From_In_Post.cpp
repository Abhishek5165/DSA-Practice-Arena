// Time Complexity: O(N); if you ignore mpps time Complxity (logN);
//  Space Complexity: O(N) for the recursion stack and the map.
// The map 'mpp' takes O(N) space to store the indices.

class Solution {
public: 
    TreeNode* solve(vector<int>& inorder,int inStart,int inEnd,
    vector<int>& postorder,int postStart,int postEnd,map<int,int>&mpp){
    
    if(postStart > postEnd || inStart > inEnd){
    return NULL;
    }

    TreeNode* root = new TreeNode(postorder[postEnd]);

    int inNode = mpp[root->val];
    int numLeft = inNode - inStart;

    root->left = solve(inorder,inStart,inNode-1,
    postorder,postStart,postStart+numLeft-1,mpp);
    
    root->right = solve(inorder,inNode+1,inEnd,
    postorder,postStart+numLeft,postEnd-1,mpp);

    return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    int m = postorder.size();

    map<int,int>mpp;
    for(int i=0;i<n;i++){
    mpp[inorder[i]] = i;
    }
    TreeNode* root = solve(inorder,0,n-1,postorder,0,m-1,mpp);
    return root;
    }
};