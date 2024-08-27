// Approch - 1 using the range 

// time complexity : O(n)
// space complexity : O(recursion stack space)

class Solution {
public: 
    bool solve(TreeNode* root, int mini,int maxxi){
    if(root == NULL){
    return true;
    }
    if((root->val > mini && root->val < maxxi) && 
    solve(root->left,mini,root->val) && 
    solve(root->right,root->val,maxxi)){
    return true;
    }
    return false;
    }

    bool isValidBST(TreeNode* root) {

    int maxxi = INT_MAX;
    int mini = INT_MIN;

    if(root == NULL){
    return true;
    }
    return solve(root,mini,maxxi);
    }
};


// Approch - 2 using inorder  

// time complexity : O(n)
// space complexity : O(n)

class Solution {
public:
  void LNR(TreeNode* root, vector<int>& vals) {
    if (root == nullptr) {
      return;
    }
    LNR(root->left, vals);
    vals.push_back(root->val);
    LNR(root->right, vals);
  }
  bool isValidBST(TreeNode* root) {
    vector<int> vals;
    LNR(root, vals);
    for (int i = 1; i < vals.size(); ++i) {
      if (vals[i] <= vals[i - 1]) {
        return false;
      }
    }
    return true;
  }
};