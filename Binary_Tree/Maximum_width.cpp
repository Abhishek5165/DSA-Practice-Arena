class Solution {
public:
    typedef unsigned long long ll;

    ll maxWidth = 0;
    
    int widthOfBinaryTree(TreeNode* root) {
        
    queue<pair<TreeNode*,ll>>Q;
    Q.push({root,0});

    while(!Q.empty()){
    
    ll size = Q.size();

    ll left = Q.front().second;
    ll right = Q.back().second;

    maxWidth = max(maxWidth,right-left+1);

    while(size--){

    TreeNode* temp = Q.front().first;
    ll index = Q.front().second;
    Q.pop();

    if(temp->left){
    Q.push({temp->left,2*index+1});
    }
    if(temp->right){
    Q.push({temp->right,2*index+2});
    }
    }
    }
    return maxWidth;
    }
};