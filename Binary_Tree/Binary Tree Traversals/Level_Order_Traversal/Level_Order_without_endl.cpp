#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int Data;
    Node *left;
    Node *right;

    //  Constructor

    Node(int D)
    {

        this->Data = D;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *Build_Tree(Node *root)
{

    int val;
    cout << "\nEnter the Node Value :";
    cin >> val;

    root = new Node(val);

    if (val == -1)
    {
        return NULL;
    }
    cout << "\nEnter the Left Node of " << val;
    root->left = Build_Tree(root->left);

    cout << "\nEnter the Right Node of " << val;
    root->right = Build_Tree(root->right);

    return root;
}

void Level_Order_traversal(Node *root)
{

    // Base Condition .....

    if (root == NULL)
    {
        return;
    }

    queue<Node *> Q;
    Q.push(root);

    while (Q.empty() == false)
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
    }
}

int main()
{

    Node *root = NULL;

    root = Build_Tree(root);

    cout << "\nThe Level order traversal is : ";

    Level_Order_traversal(root);

    return 0;
}