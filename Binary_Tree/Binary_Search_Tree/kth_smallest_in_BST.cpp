// Time Complexity: O(H + k);
// Space Complexity: O(H);

class Solution {
public:
    void solve(TreeNode* root,int &ans,int &counter,int k){
    if(root == NULL || counter >= k){
    return;
    }
    solve(root->left,ans,counter,k);
    counter++;
    if(counter == k){
    ans = root->val;
    return;
    }
    solve(root->right,ans,counter,k);
    }
    int kthSmallest(TreeNode* root, int k){

    int ans = INT_MIN;
    int counter = 0;
    solve(root,ans,counter,k);
    return ans;
    }
};