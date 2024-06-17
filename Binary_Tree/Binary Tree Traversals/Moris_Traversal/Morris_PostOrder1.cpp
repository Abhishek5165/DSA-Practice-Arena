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

void Postorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        Postorder(root->Left);
        Postorder(root->Right);
        cout << root->Data << " ";
    }
}
void printVector(vector<int>&ans){
    for(auto x :ans){
        cout<<x<<" ";
    }
}

vector<int> Morris_Traversal_PostOreder(Node *root)
{
    vector<int>V;

        Node *temp, *prev;

        temp = root;

        while (temp != NULL)
        {

            if (temp->Right == NULL)
            {
                V.push_back(temp->Data);
                temp = temp->Left;
            }
            else
            {
                prev = temp->Right;

                while (prev->Left != NULL && prev->Left != temp)
                {
                    prev = prev->Left;
                }

                if (prev->Left == NULL)
                {
                    V.push_back(temp->Data);
                    prev->Left = temp;
                    temp = temp->Right;
                }
                else
                {
                    prev->Left = NULL;
                    temp = temp->Left;
                }
            }
        }
    reverse(V.begin(),V.end());
    return V;
}
int main()
{

    Node *root = NULL;

    root = CreateBT(root);

    cout << "\nThe Postorder Traversal of the Given Tree is : ";
    Postorder(root);

    cout << "\nThe Morris Traversal of the Given Tree is : ";
    vector<int>ans =  Morris_Traversal_PostOreder(root);

    printVector(ans);

    return 0;
}