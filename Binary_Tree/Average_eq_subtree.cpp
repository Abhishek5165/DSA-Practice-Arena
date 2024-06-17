// Time complexity : O(n*n)
// Space complexity : O(n)

// Approch - 1

class Solution {
public:
    int findSum(TreeNode* &root, int &count){
    if(root == NULL){
    return 0;
    }
    count++;
    int left = findSum(root->left,count);
    int right = findSum(root->right,count);
    return (root->val + left + right);
    }

    void solve(TreeNode* &root,int &ans){
    
    if(root == NULL){
    return;
    }
    int count = 0;

    int sum = findSum(root,count);
    int average = sum/count;

    if(root->val == average){
    ans++;
    }
    solve(root->left,ans);
    solve(root->right,ans);
    }

    int averageOfSubtree(TreeNode* root) {

    int ans = 0;
    solve(root,ans);
    return ans;
    }
};


// Approch - 2 from the bottom side 

// Time complexity : O(n)
// Space complexity : O(n)


class Solution {
public:

    pair<int,int>solve(TreeNode* &root,int &ans){
    
    if(root == NULL){
    return {0,0};
    }

    int count = 0,sum = 0;

    auto P1 = solve(root->left,ans);
    auto P2 = solve(root->right,ans);
    sum = P1.first + P2.first + root->val;
    count = P1.second + P2.second + 1;

    int average = sum/count;

    if(root->val == average){
    ans++;
    }
    return {sum,count};
    }

    int averageOfSubtree(TreeNode* root) {

    int ans = 0;
    solve(root,ans);
    return ans;
    }
};