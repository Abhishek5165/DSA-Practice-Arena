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


// Optimise Version ....

// Time Complexity: O(log2N);
// Space Complexity : O(log2N) + O(H);
// The size of this result vector is proportional to the height of the Binary Tree which will be log2N when the tree is balanced and O(N) in the worst case of a skewed tree.

void solve(BinaryTreeNode<int> *root, int level, vector<int> &res) {
  if (root == NULL) {
    return;
  }
  if (res.size() == level) {
    res.push_back(root->data);
  }
  if (root->left != NULL) {
    solve(root->left, level + 1, res);
  }
  if (root->right != NULL) {
    solve(root->right, level + 1, res);
  }
}

vector<int> printLeftView(BinaryTreeNode<int> *root) {
  vector<int> res;
  solve(root, 0, res);
  return res;
}