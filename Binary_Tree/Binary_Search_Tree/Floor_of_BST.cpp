// Time Complexity: O(log2N) 
// Space Complexity : O(1)

int Floor(BinaryTreeNode<int> *node, int input)
{
	int floor = -1;
    
    while(node != NULL){
    if(input == node->data){
    return node->data;
    }
    else if(input > node->data){
    floor = node->data;
    node = node->right;
    }
    else{
    node = node->left;
    }
    }
    return floor;
}
