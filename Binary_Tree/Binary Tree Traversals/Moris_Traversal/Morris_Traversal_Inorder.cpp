

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

void Morris_Traversal_Inorder(Node *root)
{
    Node *temp, *pre;

    if (root == NULL)
    {
        return;
    }
    else{
    temp = root;
    while (temp != NULL)
    {
        if (temp->Left == NULL)
        {
            cout << temp->Data << " ";
            temp = temp->Right;
        }
        else
        {
            pre = temp->Left;

            while (pre->Right != NULL && pre->Right != temp)
            {
                pre = pre->Right;
            }
            if (pre->Right == NULL)
            {

                pre->Right = temp;
                temp = temp->Left;
            }
            else
            {
                pre->Right = NULL;
                cout << temp->Data << " ";
                temp = temp->Right;
            }
        }
    }
}
}

int main()
{

    Node *root = NULL;

    root = CreateBT(root);
    cout << "\nThe Inorder Traversal of the Given Tree is : ";
    Inorder(root);

    cout << "\nThe Morris Traversal of the Given Tree is : ";
    Morris_Traversal_Inorder(root);

    return 0;
}