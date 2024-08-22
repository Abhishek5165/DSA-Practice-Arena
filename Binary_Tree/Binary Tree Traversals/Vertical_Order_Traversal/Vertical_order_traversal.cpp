// Time Complexity : O(N∗Log(N));
// Space Complexity : O(N);

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>>ans;
    if(root == NULL){
    return ans;
    }
    map<int,map<int,multiset<int>>>mpp;
    queue<pair<TreeNode*,pair<int,int>>>Q;
    Q.push({root,{0,0}});

    while(!Q.empty()){
    
    auto A = Q.front();
    Q.pop();

    TreeNode* node = A.first;
    int vertical = A.second.first;
    int level = A.second.second;

    mpp[vertical][level].insert(node->val);

    if(node->left != NULL){
    Q.push({node->left,{vertical-1,level+1}});
    }
    if(node->right != NULL){
    Q.push({node->right,{vertical+1,level+1}});
    }
    }
    for(auto p : mpp){
    vector<int>temp;
    for(auto q : p.second){
    temp.insert(temp.end(), q.second.begin(),q.second.end());
    }
    ans.push_back(temp);
    }
    return ans;
    }
};