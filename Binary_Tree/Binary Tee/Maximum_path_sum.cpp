// Time Complexity: O(N) where N is the number of nodes in the Binary Tree.

// Space Complexity: O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space.

class Solution {
public:
    int Sum(TreeNode* root,int &maxxi){
    if(root == NULL){
    return 0;
    }
    int sum = 0;
    int LeftSum = max(0,Sum(root->left,maxxi));
    int RightSum = max(0,Sum(root->right,maxxi));

    sum = LeftSum + RightSum + root->val;

    maxxi = max(sum,maxxi);
    
    return (root->val + max(LeftSum,RightSum));
    }
    int maxPathSum(TreeNode* root) {
    int maxxi = INT_MIN;
    Sum(root,maxxi);
    return maxxi;
    }
};
