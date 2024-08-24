// Time Complexity: O(N); if you ignore mpps time Complxity (logN);
//  Space Complexity: O(N) for the recursion stack and the map.
// The map 'mpp' takes O(N) space to store the indices.

class Solution {
public:
    
    TreeNode* solve(vector<int>& inorder,int inStart,int inEnd,
    vector<int>& preorder,int preStart,int preEnd,map<int,int>&mpp){
    
    if(preStart > preEnd || inStart > inEnd){
    return NULL;
    }

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inNode = mpp[root->val];
    int numLeft = inNode - inStart;

    root->left = solve(inorder,inStart,inNode-1,
    preorder,preStart+1,preStart+numLeft,mpp);
    
    root->right = solve(inorder,inNode+1,inEnd,
    preorder,preStart+numLeft+1,preEnd,mpp);

    return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        
    int n = inorder.size();
    int m = preorder.size();

    map<int,int>mpp;
    for(int i=0;i<n;i++){
    mpp[inorder[i]] = i;
    }
    TreeNode* root = solve(inorder,0,n-1,preorder,0,m-1,mpp);
    return root;
    }
};
