/************************************************************

Time Complexity : Time Complexity: O(N) where N is the number of nodes in the BT.

Space Complexity : Space Complexity: O(N) where N is the number of nodes in the Binary Tree to store the boundary nodes of the tree. O(H) or O(log2N) Recursive stack space while traversing the tree.

************************************************************/

bool isLeaf(TreeNode<int> *root) { return (!root->left && !root->right); }

void addLeft(TreeNode<int> *root, vector<int> &Abhishek) {

  TreeNode<int> *curr = root->left;
  if (curr == NULL) {
    return;
  }
  while (curr != NULL) {
    if (!isLeaf(curr)) {
      Abhishek.push_back(curr->data);
    }
    if (curr->left != NULL) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }
}

void addRight(TreeNode<int> *root, vector<int> &Abhishek) {

  TreeNode<int> *curr = root->right;
  vector<int> temp;
  while (curr != NULL) {
    if (!isLeaf(curr)) {
      temp.push_back(curr->data);
    }
    if (curr->right != NULL) {
      curr = curr->right;
    } else {
      curr = curr->left;
    }
  }
  for (int i = temp.size() - 1; i >= 0; i--) {
    Abhishek.push_back(temp[i]);
  }
}

void addBottom(TreeNode<int> *root, vector<int> &Abhishek) {

  TreeNode<int> *curr = root;
  if (isLeaf(curr)) {
    Abhishek.push_back(curr->data);
  }
  if (curr->left != NULL) {
    addBottom(root->left, Abhishek);
  }
  if (curr->right != NULL) {
    addBottom(root->right, Abhishek);
  }
}

vector<int> traverseBoundary(TreeNode<int> *root) {

  vector<int> Abhishek;
  if (root == NULL) {
    return Abhishek;
  }
  if (!isLeaf(root)) {
    Abhishek.push_back(root->data);
  }
  // adding the left boundary....
  addLeft(root, Abhishek);
  // adding the bottom boundary....
  addBottom(root, Abhishek);
  // adding the Right boundary....
  addRight(root, Abhishek);

  return Abhishek;
}
