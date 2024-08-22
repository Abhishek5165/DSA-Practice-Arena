// Time Complexity : O(N);
// Space Complexity : O(N)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>Level;
    
    if(root == NULL){
    return Level;
    }  
    bool flag = true;
    queue<TreeNode*>Q;
    Q.push(root);
    while(!Q.empty()){
    int size = Q.size();
    vector<int>ans(size);

    for(int i=0;i<size;i++){
    TreeNode* node = Q.front();
    Q.pop();

    int index = (flag) ? i : size-i-1;
    ans[index] = node->val;

    if(node->left != NULL){
    Q.push(node->left);
    }
    if(node->right != NULL){
    Q.push(node->right);
    }
    }
    flag = !flag;
    Level.push_back(ans);
    }
    return Level;
    }
};