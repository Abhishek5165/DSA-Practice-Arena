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