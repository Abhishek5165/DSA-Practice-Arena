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

void InOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        InOrder(root->left);
        cout << root->Data << " ";
        InOrder(root->right);
    }
}

void InOrder_Using_One_Stack(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        stack<Node *> S;
        Node *temp = root;

        while (true)
        {
            if (temp != NULL)
            {
                S.push(temp);
                temp = temp->left;
            }
            else if(S.empty()==true){
                break;
            }
            else{
            temp = S.top();
            S.pop();
            cout << temp->Data << " ";
            temp = temp->right;
            }
        }
    }
    }

int main()
{

    Node *root = NULL;
    root = CreateBT(root);

    cout << "\nThe InOrder Traversal of the Given Binary Tree is : ";
    InOrder(root);

    cout << "\nThe InOrder Traversal of the Given Binary Tree using Stack : ";
    InOrder_Using_One_Stack(root);

    return 0;
}