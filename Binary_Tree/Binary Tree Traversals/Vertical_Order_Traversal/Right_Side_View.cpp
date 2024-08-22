// Brute Force ....
// Time Complexity: O(N);
// Space Complexity: O(N);

class Solution {
public:
    
    vector<vector<int>>LevelOrder(TreeNode* root){
    
    vector<int>temp;
    vector<vector<int>>ans;

    if(root == NULL){
    return ans;
    }
    queue<TreeNode*>Q;
    Q.push(root);

    while(!Q.empty()){
    int size = Q.size();
    temp.clear();

    while(size--){
    TreeNode* node = Q.front();
    Q.pop();

    temp.push_back(node->val);
    if(node->left != NULL){
    Q.push(node->left);
    }
    if(node->right != NULL){
    Q.push(node->right);
    }
    }
    ans.push_back(temp);
    }
    return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
    vector<vector<int>>Level;
    vector<int>ans;
    if(root == NULL){
    return ans;
    }   
    Level = LevelOrder(root);
    for(auto vec : Level){
    ans.push_back(vec.back());
    }
    return ans;
    }
};

// Optimise Version ....

// Time Complexity: O(log2N);
// Space Complexity : O(log2N) + O(H);
// The size of this result vector is proportional to the height of the Binary Tree which will be log2N when the tree is balanced and O(N) in the worst case of a skewed tree.

class Solution {
public:
    void solve(TreeNode* root,int level,vector<int>&res){
    if(root == NULL){
    return;
    }
    if(res.size() == level){
    res.push_back(root->val);
    }
    if(root->right != NULL){
    solve(root->right,level+1,res);
    }
    if(root->left != NULL){
    solve(root->left,level+1,res);
    }
    }
    vector<int> rightSideView(TreeNode* root) {
    vector<int>res;
    solve(root,0,res);
    return res;
    }
};
