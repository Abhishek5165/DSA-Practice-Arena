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

Node *create(Node *root)
{

    int value;
    Node *newNode = new Node(value);
    cout << "\nEnter the Node value : ";
    cin >> value;

    if (value == -1)
    {
        return NULL;
    }

    newNode->Data = value;

    cout << "\nEnter the Left Node Value for the Node " << value;
    newNode->left = create(root);

    cout << "\nEnter the Right Node Value for the Node " << value;
    newNode->right = create(root);

    return newNode;
}

void Inorder_traversal(Node *root)
{

    // base condition .............

    if (root == NULL)
    {
        return;
    }

    Inorder_traversal(root->left);
    cout << root->Data << " ";
    Inorder_traversal(root->right);
}

void Preorder_traversal(Node *root)
{

    // base condition .............

    if (root == NULL)
    {
        return;
    }

    cout << root->Data << " ";
    Preorder_traversal(root->left);
    Preorder_traversal(root->right);
}

void Postorder_traversal(Node *root)
{

    // base condition .............

    if (root == NULL)
    {
        return;
    }

    Postorder_traversal(root->left);
    Postorder_traversal(root->right);
    cout << root->Data << " ";
}

void Level_Order_Approch1(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
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
                if (Q.empty() == false)
                {
                    Q.push(NULL);
                }
            }
            else
            {
                if (temp->left != NULL)
                {
                    Q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    Q.push(temp->right);
                }
                cout << temp->Data << " ";
            }
        }
    }
}

void Level_Order_Approch2(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        queue<Node *> Q;
        Q.push(root);

        while (Q.empty() == false)
        {

            int size = Q.size();
            while (size > 0)
            {
                Node *temp = Q.front();
                Q.pop();
                if (temp->left != NULL)
                {
                    Q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    Q.push(temp->right);
                }
                cout<<temp->Data<<" ";
                size--;
            }
            cout<<endl;
        }
    }
}

int main()
{

    Node *root = NULL;

    root = create(root);

    cout << "\nThe Inorder traversal is : ";
    Inorder_traversal(root);

    cout << "\nThe Preorder traversal is : ";
    Preorder_traversal(root);

    cout << "\nThe Postorder traversal is : ";
    Postorder_traversal(root);

    cout << "\nThe LeveL_Order_traversal_using_Approch1 is : " << endl;
    Level_Order_Approch1(root);

    cout << "\nThe LeveL_Order_traversal_using_Approch2 is : " << endl;
    Level_Order_Approch2(root);

    cout << endl
         << "Thank You !";

    return 0;
}