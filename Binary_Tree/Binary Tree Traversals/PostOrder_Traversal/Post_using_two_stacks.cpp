class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    vector<int>ans;
    if(root == NULL){
    return ans;
    } 

    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    st1.push(root);

    while(!st1.empty()){

    TreeNode* node = st1.top();
    st1.pop();

    st2.push(node);
  
    if(node->left != NULL){
    st1.push(node->left);
    }
    if(node->right != NULL){
    st1.push(node->right);
    }
    }
    while(!st2.empty()){
    TreeNode* node = st2.top();
    st2.pop();
    ans.push_back(node->val);
    }
    return ans;
    }
};