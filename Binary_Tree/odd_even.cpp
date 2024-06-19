// Time Complexity : O(n)
// Space Complexity : O(n)

// Approch - 1 Using BFS 

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {

    queue<TreeNode*>Q;
    Q.push(root);

    bool level = true;

    while(!Q.empty()){

    int size = Q.size();
    int prev;

    if(level){
    prev = INT_MIN;
    }
    else{
    prev = INT_MAX;
    }

    while(size--){

    TreeNode* temp = Q.front();
    Q.pop();

    if(level && (!(temp->val&1) || temp->val <= prev)){
    return false;
    }
    if(!level && ((temp->val&1) || temp->val >= prev)){
    return false;
    }
    prev = temp->val;

    if(temp->left){
    Q.push(temp->left);
    }
    if(temp->right){
    Q.push(temp->right);
    }
    }
    level = !level;
    }
    return true;
    }
};


// Time Complexity : O(n*n) in worst case => for resize we copy all elements then store new 

// Auxilary Space Complexity : O(level) or O(height)

// Approch - 2 Using DFS

class Solution {
public:
    vector<int>ans;

    bool solve(TreeNode* &root,int level){

    if(root == NULL){
    return true;
    }

    if((level%2 == 0 && root->val%2 == 0) || 
    (level%2 != 0 && root->val%2 != 0)){
    return false;
    }
    if(level >= ans.size()){
    ans.resize(level+1);
    }
    if(ans[level] != 0){

    if((level%2 == 0 && root->val <= ans[level]) ||
    (level%2 != 0 && root->val >= ans[level])){
    return false;
    }
    }
    ans[level] = root->val;
    return solve(root->left,level+1) 
    && solve(root->right,level+1);
    }
    bool isEvenOddTree(TreeNode* root) {
    return solve(root,0);
    }
};