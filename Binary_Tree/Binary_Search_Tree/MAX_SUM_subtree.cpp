// time complexity = O(N)
// space complexity = O(N)

class Solution {
   
    int ans = 0;

public:
   
    vector<int>solve(TreeNode* root){

    if(root == NULL){
    return {INT_MAX,INT_MIN,0};
    }
    vector<int>left = solve(root->left);
    vector<int>right = solve(root->right);
    

    if(!(root->val > left[1] && root->val < right[0])){
    return {INT_MIN,INT_MAX,0};
    }

    int sum = left[2] + right[2] + root->val;
    ans = max(sum,ans);

    int mini = min(root->val,left[0]);
    int maxi = max(right[1],root->val);

    return {mini,maxi,sum};
    }

    int maxSumBST(TreeNode* root) {
    
    vector<int>tree = solve(root);
    return ans;
    }
};