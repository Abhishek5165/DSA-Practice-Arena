// time complexity : O(1);
// space complexity : O(h);

class BSTIterator {
public:
    stack<TreeNode*>st;

    BSTIterator(TreeNode* root) {
    pushALL(root);
    }

    void pushALL(TreeNode* node){

    while(node!=NULL){

    st.push(node);
    node = node->left;
    }
    }
    
    int next() {
    
    TreeNode* temp = st.top();
    st.pop();
    pushALL(temp->right);
    return temp->val;
    }
    
    bool hasNext() {
    return !st.empty(); 
    }
};

// Another approch store the inorder in vector and then give the output accordingly

// time complexity : O(1);
// space complexity : O(n);