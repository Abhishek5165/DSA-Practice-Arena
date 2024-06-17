#include <iostream>
#include <stack>
using namespace std;

class Node
{

public:
    int Data;
    Node *left;
    Node *right;

    Node(int D)
    {

        this->Data = D;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *CreateBT(Node *&root)
{

    int val;
    cout << "\nEnter the Node Value :";
    cin >> val;

    root = new Node(val);

    if (val == -1)
    {
        return NULL;
    }
    else
    {

        cout << "\nEnter the Left Node Value of the Node " << val;
        root->left = CreateBT(root->left);

        cout << "\nEnter the Right Node Value of the Node " << val;
        root->right = CreateBT(root->right);
    }
    return root;
}

void Preorder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->Data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Morris(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->left == NULL)
            {
                cout << temp->Data << " ";
                temp = temp->right;
            }
            else
            {
                Node *prev = temp->left;
                while (prev->right != NULL && prev->right != temp)
                {
                    prev = prev->right;
                }
                    if (prev->right == NULL)
                    {
                        prev->right = temp;
                        cout << temp->Data << " ";
                        temp = temp->left;
                    }
                    else
                    {
                        prev->right = NULL;
                        temp = temp->right;
                    }
            }
        }
    }
}

int main()
{

    Node *root = NULL;
    root = CreateBT(root);

    cout << "\nThe Preorder Traversal of the Given Binary Tree is : ";
    Preorder(root);

    cout << "\nThe Preorder Traversal of the Given Binary Tree Using Morris Traversal is : ";
    Morris(root);
    return 0;
}