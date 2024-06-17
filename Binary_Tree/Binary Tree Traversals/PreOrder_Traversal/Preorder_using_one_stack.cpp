
#include <iostream>
#include <stack>
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

Node *CreateBT(Node *&root)
{

    int Val;
    cout << "\nEnter the Node Value : ";
    cin >> Val;

    root = new Node(Val);

    if (Val == -1)
    {
        return NULL;
    }
    else
    {

        cout << "\nEnter the Left Node Value of the Node " << Val;
        root->Left = CreateBT(root->Left);

        cout << "\nEnter the Right Node Value of the Node " << Val;
        root->Right = CreateBT(root->Right);

        return root;
    }
}

void Preorder_using_recursion(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->Data << " ";
        Preorder_using_recursion(root->Left);
        Preorder_using_recursion(root->Right);
    }
}
void Preorder_using_one_stack(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        stack<Node *> s;
        Node *temp = root;
        while (temp != NULL || s.empty() == false)
        {
            while (temp != NULL)
            {
                cout << temp->Data << " ";

                if (temp->Right != NULL)
                {
                    s.push(temp->Right);
                }
                temp = temp->Left;
            }

            if (s.empty() == false)
            {
                temp = s.top();
                s.pop();
            }
        }
    }
}
int main()
{

    Node *root = NULL;

    root = CreateBT(root);

    cout << "\nThe Preorder Traversal of the BT is : ";
    Preorder_using_recursion(root);

    cout << "\nThe Preorder Traversal of the BT is : ";
    Preorder_using_one_stack(root);
}
