// Time Complexity: O(N);
// Space Complexity: O(log2N);

//  In the ideal case, H = log2N and in the worst case H = N (skewed tree).

void flatten(TreeNode* root) {
       // Base case: If the current
       // node is NULL, return.
       if(root==NULL){
           return;
       }

       // Recursive call to
       // flatten the right subtree
       flatten(root->right);
       
       // Recursive call to
       // flatten the left subtree
       flatten(root->left);
       
       // At this point, both left and right
       // subtrees are flattened, and 'prev'
       // is pointing to the rightmost node
       // in the flattened right subtree.

       // Set the right child of
       // the current node to 'prev'.
       root->right = prev;

       // Set the left child of the
       // current node to NULL.
       root->left = NULL;

       // Update 'prev' to the current
       // node for the next iteration.
       prev = root;
    }
};


// Better Approch - Using Stack...
// Time Complexity: O(N);
// Space Complexity: O(N);


void flatten(TreeNode* root) {
        // Base case: If the current
        // node is NULL, return.
        if(root == NULL){
            return;
        }
        // Use a stack for
        // iterative traversal.
        stack<TreeNode*> st;
        // Push the root node
        // onto the stack.
        st.push(root);  
        
        // Continue the loop until
        // the stack is empty.
        while (!st.empty()) {  
            // Get the top node from the stack.
            TreeNode* cur = st.top(); 
            // Pop the top node.
            st.pop();  

            if (cur->right != NULL) {
                 // Push the right child
                 // onto the stack.
                st.push(cur->right); 
            }
            
            if (cur->left != NULL) {
                 // Push the left child
                 // onto the stack.
                st.push(cur->left); 
            }

            if (!st.empty()) {
                // Connect the right child to
                // the next node in the stack.
                cur->right = st.top();  
            }
            
            // Set the left child to NULL to
            // form a right-oriented linked list.
            cur->left = NULL;  
        }
    }
};

// Optimise Approch ....

// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    void flatten(TreeNode* root) {
    TreeNode* curr = root;
    TreeNode* prev;

    while(curr != NULL){
    if(curr->left != NULL){
    prev = curr->left;
    
    while(prev->right){
    prev = prev->right;
    }
    prev->right = curr->right;
    curr->right = curr->left;
    curr->left =  NULL;
    }
    curr = curr->right;
    }
    }
};