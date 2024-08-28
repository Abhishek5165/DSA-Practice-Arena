// Time Complexity : O(m+n);
// Space Complexity : O(Height of BST1 + Height of BST2 + m + n);

class Solution {
  public:
    
    void solve(Node* root,vector<int>&In){
    if(root == NULL){
    return;
    }
    solve(root->left,In);
    In.push_back(root->data);
    solve(root->right,In);
    }
    
    void merge(vector<int>&In1,vector<int>&In2,vector<int>&ans){
    
    int i=0;
    int j=0;
    int k = 0;
    
    int n = In1.size();
    int m = In2.size();
    
    ans.resize(n+m);
    
    while(i<n && j<m){
    
    if(In1[i] < In2[j]){
    ans[k] = In1[i];
    i++;
    }
    else{
    ans[k] = In2[j];
    j++;
    }
    k++;
    }
    while(i<n){
    ans[k] = In1[i];
    i++;
    k++;
    }
    while(j<m){
    ans[k] = In2[j];
    j++;
    k++;
    }
    }

    vector<int> merge(Node *root1, Node *root2) {
        
    vector<int>ans;
    
    vector<int>In1;
    vector<int>In2;
    
    solve(root1,In1);
    solve(root2,In2);
    
    merge(In1,In2,ans);
    return ans;
    }
};