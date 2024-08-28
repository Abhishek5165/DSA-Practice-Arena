// Time Complexity : O(N);
// Space Complexity : O(H);

class NodeValue{
public:
int mini;
int maxxi;
int maxSize;

NodeValue(int mini,int maxxi,int maxSize){
this->mini = mini;
this->maxxi = maxxi;
this->maxSize = maxSize;
}
};

class Solution{
    private: 
    
    NodeValue Helper(Node* root){
    
    if(root == NULL){
    return NodeValue(INT_MAX,INT_MIN,0);
    }
    
    auto Left = Helper(root->left);
    auto Right = Helper(root->right);
    
    if(Left.maxxi < root->data && root->data < Right.mini){
        
    return NodeValue(min(Left.mini,root->data),max(Right.maxxi,
    root->data),1 + Left.maxSize + Right.maxSize);
    }
    
    else{
    return NodeValue(INT_MIN,INT_MAX,max(Left.maxSize,Right.maxSize));
    }
    }
    public:
    int largestBst(Node *root){
    return Helper(root).maxSize;
    }
};