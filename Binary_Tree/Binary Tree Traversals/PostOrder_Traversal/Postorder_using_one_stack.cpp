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

void Postorder_using_recursion(Node *root){

    if(root == NULL){
    return;
    }
    else{

    Postorder_using_recursion(root->Left);
    Postorder_using_recursion(root->Right);
    cout<<root->Data<<" ";
    }
}
void Postorder_using_one_stack(Node *root){


}

int main(){

    Node *root = NULL;

    root = CreateBT(root);

    cout<<"\nThe Postorder Traversal of the BT is : ";
    Postorder_using_recursion(root);

    cout<<"\nThe Postorder Traversal of the BT is : ";
    Postorder_using_one_stack(root);


}
