#include <bits/stdc++.h>
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

Node *Create_BinaryTree(Node *root)
{

    int val;
    cout << "\nEnter the Node Value : ";
    cin >> val;

    root = new Node(val);

    if (val == -1)
    {
        return NULL;
    }

    cout << "\nEnter the Left Node Value of the Node " << val;
    root->left = Create_BinaryTree(root->left);

    cout << "\nEnter the Right Node Value of the Node " << val;
    root->right = Create_BinaryTree(root->right);

    return root;
}

void Level_Order_Traversal(Node *root)
{

    // Base Condition  ...........

    if (root == NULL)
    {
        return;
    }

    queue<Node *> Q;

    Q.push(root);
    Q.push(NULL);

    while (Q.empty() == false)
    {

        Node *temp = Q.front();
        Q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (Q.empty()==false)
            {
                Q.push(NULL);
            }
        }
        else
        {
            cout << temp->Data << " ";
            if (temp->left != NULL)
            {
                Q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                Q.push(temp->right);
            }
        }
    }
}

void InOrder(Node *root)
{

    // Base Condition ..............

    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->Data << " ";
    InOrder(root->right);
}

int main()
{
    Node *root = NULL;

    root = Create_BinaryTree(root);

    cout << "\nThe Inorder Traversal of the Tree is : ";
    InOrder(root);

    cout << "\nThe Lavel Order Traversal of the Tree is : "<<endl;
    Level_Order_Traversal(root);

    return 0;
}