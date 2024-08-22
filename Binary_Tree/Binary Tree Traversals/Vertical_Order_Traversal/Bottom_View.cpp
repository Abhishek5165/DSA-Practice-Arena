// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
  public:
  vector <int> bottomView(Node *root) {
  vector<int> ans;
  if (root == NULL) {
    return ans;
  }
  map<int,int> mpp;
  queue<pair<Node*,int>> Q;
  Q.push({root,0});

  while (!Q.empty()) {

    auto A = Q.front();
    Q.pop();

    Node* node = A.first;
    int vertical = A.second;

    mpp[vertical] = (node->data);

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
};