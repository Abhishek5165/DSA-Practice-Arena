#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int Data;
    Node *Left;
    Node *Right;

    Node(int D)
    {
        this->Data = D;
        this->Left = NULL;
        this->Right = NULL;
    }
};

Node *CreateBT(Node *root)
{

    int val;
    cout << "\nEnter the Node Value : ";
    cin >> val;

    root = new Node(val);

    // Base Case ...........

    if (val == -1)
    {
        return NULL;
    }
    else
    {
        cout << "\nEnter the Left Node Value of the Node " << val;
        root->Left = CreateBT(root->Left);

        cout << "\nEnter the Right Node Value of the Node " << val;
        root->Right = CreateBT(root->Right);

        return root;
    }
}

void Inorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        Inorder(root->Left);
        cout << root->Data << " ";
        Inorder(root->Right);
    }
}


void MorrisTraversal(Node* root)
{
    Node *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
 
        if (current->Left == NULL) {
            cout << current->Data << " ";
            current = current->Right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->Left;
            while (pre->Right != NULL && pre->Right != current)
                pre = pre->Right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->Right == NULL) {
                pre->Right = current;
                current = current->Left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->Right = NULL;
                cout << current->Data << " ";
                current = current->Right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}
 


int main()
{

    Node *root = NULL;

    root = CreateBT(root);

    cout << "\nThe Inorder Traversal of the Given Tree is : ";
    Inorder(root);

    cout << "\nThe Morris Traversal of the Given Tree is : ";
    MorrisTraversal(root);

    return 0;
}