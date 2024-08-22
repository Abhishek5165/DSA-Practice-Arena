// Time Complexity : O(N);
// Space Complexity : O(N);

#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
  vector<int> ans;
  if (root == NULL) {
    return ans;
  }
  map<int,int> mpp;
  queue<pair<TreeNode<int>*,int>> Q;
  Q.push({root,0});

  while (!Q.empty()) {

    auto A = Q.front();
    Q.pop();

    TreeNode<int>* node = A.first;
    int vertical = A.second;

    if(mpp.find(vertical) == mpp.end()){
    mpp[vertical] = (node->data);
    }

    if (node->left != NULL) {
      Q.push({node->left,vertical - 1});
    }
    if (node->right != NULL) {
      Q.push({node->right,vertical + 1});
    }
  }
  for(auto p : mpp){
  ans.push_back(p.second);
  }
  return ans;
}
