// Brute Force ....
// Time Complexity: O(N);
// Space Complexity: O(N);


vector<vector<int>> LevelOrder(BinaryTreeNode<int>*root) {

  vector<int> temp;
  vector<vector<int>> ans;

  if (root == NULL) {
    return ans;
  }
  queue<BinaryTreeNode<int>*>Q;
  Q.push(root);

  while (!Q.empty()) {
    int size = Q.size();
    temp.clear();

    while (size--) {
      BinaryTreeNode<int> *node = Q.front();
      Q.pop();

      temp.push_back(node->data);
      if (node->left != NULL) {
        Q.push(node->left);
      }
      if (node->right != NULL) {
        Q.push(node->right);
      }
    }
    ans.push_back(temp);
  }
  return ans;
}

vector<int> printLeftView(BinaryTreeNode<int> *root) {
  vector<vector<int>> Level;
  vector<int> ans;
  if (root == NULL) {
    return ans;
  }
  Level = LevelOrder(root);
  for (auto &vec : Level) {
    ans.push_back(vec.front());
  }
  return ans;
}
