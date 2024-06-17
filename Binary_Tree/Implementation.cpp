#include <iostream>
#include<queue>
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

Node *Create(Node *root)
{

    cout << "\nEnter the Node value : ";
    int val;
    cin >> val;

    root = new Node(val);

    // Base condition

    if (val == -1)
    {
        return NULL;
    }
    cout << "\nEnter The Left Node Value of the Node " << val;
    root->left = Create(root->left);

    cout << "\nEnter The Right Node Value of the Node " << val;
    root->right = Create(root->right);

    return root;
}

void Inorder_recursion(Node *root)
{

    // base condition

    if (root == NULL)
    {
        return;
    }

    Inorder_recursion(root->left);
    cout << root->Data << " ";
    Inorder_recursion(root->right);
}

void Preorder_recursion(Node *root)
{

    // base condition

    if (root == NULL)
    {
        return;
    }

    cout << root->Data << " ";
    Inorder_recursion(root->left);
    Inorder_recursion(root->right);
}

void Postorder_recursion(Node *root)
{

    // base condition

    if (root == NULL)
    {
        return;
    }

    Inorder_recursion(root->left);
    Inorder_recursion(root->right);
    cout << root->Data << " ";
}

void Levelorder_recursion(Node *root)
{

    // base condition

    if (root == NULL)
    {
        return;
    }

    queue<Node *> Q;
    Q.push(root);

    while (Q.empty() == false)
    {
        int Size = Q.size();

        while (Size > 0)
        {
            Node *temp = Q.front();
            cout << temp->Data << " ";
            Q.pop();

            if (temp->left != NULL)
            {
                Q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                Q.push(temp->right);
            }
            Size--;
        }
        cout << endl;
    }
}

int main()
{

    Node *root = NULL;

    root = Create(root);

    cout << "\nThe Inorder Traversal of the given Binary Tree is : ";
    Inorder_recursion(root);

    cout << "\nThe Preorder Traversal of the given Binary Tree is : ";
    Preorder_recursion(root);

    cout << "\nThe Postorder Traversal of the given Binary Tree is : ";
    Postorder_recursion(root);

    cout << "\nThe Levelorder Traversal of the given Binary Tree is :\n"
         << endl;
    Levelorder_recursion(root);

    return 0;
}