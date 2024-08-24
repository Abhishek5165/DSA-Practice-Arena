// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
  public:
    void solve(Node* root,vector<vector<int>>&ans){
    vector<int>temp;
    temp.push_back(root->data);
    
    if(root && !root->left && !root->right){
    ans.push_back(temp);
    return;
    }
    if(root->left){
    solve(root->left,ans);
    }
    if(root->right){
    solve(root->right,ans);
    }
    }
    
    vector<vector<int>> Paths(Node* root) {
    vector<vector<int>>ans;
    
    if(root == NULL){
    return ans;
    }
    solve(root,ans);
    return ans;
    }
};


// In the Form of String .....
// Time Complexity : O(N)
// Space Complexity : O(N)

void dfs(BinaryTreeNode<int> *root, string path, vector<string> &ans) {

  if (root == NULL){
    return;
  }

  path += to_string(root->data);
  path += " ";

  if (root->left == NULL && root->right == NULL) {
    ans.push_back(path);
    return;
  }
  dfs(root->left, path, ans);
  dfs(root->right, path, ans);
}

vector<string> allRootToLeaf(BinaryTreeNode<int> *root) {

  vector<string> ans;
  dfs(root, "", ans);
  return ans;
}