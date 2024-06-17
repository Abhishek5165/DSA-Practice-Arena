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

void Inorder_using_recursion(Node *root){

    if(root == NULL){
    return;
    }
    else{

    Inorder_using_recursion(root->Left);
    cout<<root->Data<<" ";
    Inorder_using_recursion(root->Right);
    }
}
void Inorder_using_one_stack(Node *root){

stack<Node*> s;
Node *temp = root;

if(temp==NULL){
    return;
}
else{

while(temp!=NULL || s.empty()==false){

    while(temp!=NULL){

        s.push(temp);
        temp = temp->Left;
    }
    temp = s.top();
    s.pop();
    cout<<temp->Data<<" ";
    temp = temp->Right;
}
}
}

int main(){

    Node *root = NULL;

    root = CreateBT(root);

    cout<<"\nThe Inorder Traversal of the BT is : ";
    Inorder_using_recursion(root);

    cout<<"\nThe Inorder Traversal of the BT is : ";
    Inorder_using_one_stack(root);


}
