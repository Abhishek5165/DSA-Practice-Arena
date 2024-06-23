// Approch - 1 using the range 

// time complexity : O(n)
// space complexity : O(recursion stack space)

class Solution {
public:
    bool ans(TreeNode* root,long left,long  right) {

        if (root == NULL) {
            return true;
        }
        if(root->val <= left || root->val >= right){
        return false;
        }
        return ans(root->left,left,root->val) && 
        ans(root->right,root->val,right);
    }
    bool isValidBST(TreeNode* root) {
    
    if(root == NULL){
        return true;
    }
    long left = LONG_MIN;
    long right = LONG_MAX;

    return ans(root,left,right);
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