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

void Postorder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->Data << " ";
    }
}

vector<int> Morris(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    vector<int>ans;
    Node *temp = root;
    Node*pre;
     while(temp != NULL){
            if(temp->right == NULL){
                 ans.push_back(temp->Data);
                temp = temp->left;
            }
            else{
                pre = temp->right;
                while(pre->left != NULL && pre->left != temp)
                    pre = pre->left;
                
                if(pre->left == NULL){
                   ans.push_back(temp->Data);
                    pre->left = temp;
                    temp = temp->right;
                }
                else{
                    pre->left = NULL;
                    temp = temp->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
}

int main()
{

    Node *root = NULL;
    root = CreateBT(root);

    cout << "\nThe Postorder Traversal of the Given Binary Tree is : ";
    Postorder(root);

    cout << "\nThe Postorder Traversal of the Given Binary Tree Using Morris Traversal is : ";
    Morris(root);
    return 0;
}