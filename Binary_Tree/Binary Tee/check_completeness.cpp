// time complexity : O(n);
// space complexity : O(n);


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
    if(root == NULL){
    return true;
    }
    bool past = false;
    queue<TreeNode*>Q;
    Q.push(root);

    while(Q.empty()==false){

    TreeNode* temp = Q.front();
    Q.pop();

    if(temp == NULL){
    past = true;
    }
    else{
        if(past == true){
        return false;
        }
    Q.push(temp->left);
    Q.push(temp->right);
    }
    }
    return true;
    }
};