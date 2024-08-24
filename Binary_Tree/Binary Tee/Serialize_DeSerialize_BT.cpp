// Time Complexity : O(N); 
// Time Complexity : O(N);

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    
    if(root == NULL){
    return "";
    }
    string s = "";
    queue<TreeNode*>Q;
    Q.push(root);

    while(!Q.empty()){
    TreeNode* temp = Q.front();
    Q.pop();

    if(temp == NULL){
    s += ("#,");
    }
    else{
    s += (to_string(temp->val) + ',');
    }
    if(temp != NULL){
    Q.push(temp->left);
    Q.push(temp->right);
    }
    }
    return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if(data == ""){
    return NULL;
    }
    stringstream s(data);
    string str;
    getline(s,str,',');

    TreeNode* root = new TreeNode(stoi(str));

    queue<TreeNode*>Q;
    Q.push(root);

    while(!Q.empty()){
    TreeNode* temp = Q.front();
    Q.pop();

    getline(s,str,',');
    if(str == "#"){
    temp->left = NULL;
    }
    else{
    TreeNode* Left = new TreeNode(stoi(str));
    temp->left = Left;
    Q.push(Left);
    }

    getline(s,str,',');
    if(str == "#"){
    temp->right = NULL;
    }
    else{
    TreeNode* Right = new TreeNode(stoi(str));
    temp->right = Right;
    Q.push(Right);
    }
    }
    return root;
    }
};
