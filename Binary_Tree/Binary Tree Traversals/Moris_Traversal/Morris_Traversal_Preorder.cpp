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

void Preorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->Data << " ";
        Preorder(root->Left);
        Preorder(root->Right);
    }
}

void Morris_Traversal_Preorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        Node *temp, *prev;
       
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
                prev = temp->Left;

                while (prev->Right != NULL && prev->Right != temp)
                {
                    prev = prev->Right;
                }
                if (prev->Right == temp)
                {
                    prev->Right = NULL;
                    temp = temp->Right;
                }
                else
                {
                    cout << temp->Data << " ";
                    prev->Right = temp;
                    temp = temp->Left;
                }
            }
        }
    }
}

int main()
{

    Node *root = NULL;

    root = CreateBT(root);

    cout << "\nThe Preorder Traversal of the Given Tree is : ";
    Preorder(root);

    cout << "\nThe Morris Traversal of the Given Tree is : ";
    Morris_Traversal_Preorder(root);

    return 0;
}