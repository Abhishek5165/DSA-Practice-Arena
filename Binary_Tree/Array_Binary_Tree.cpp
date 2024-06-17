#include <bits/stdc++.h>

Node *createTree(vector<int> &arr)
{

    int size = arr.size();

    if (size == 0)
    {
        return NULL;
    }

    int i = 0;

    queue<Node *> Q;
    Node *root = new Node(arr[0]);

    Q.push(root);

    while (!Q.empty() && i < 3)
    {

        Node *temp = Q.front();
        Q.pop();

        Node *L = new Node(arr[2 * i + 1]);
        Q.push(L);
        temp->left = L;

        Node *R = new Node(arr[2 * i + 2]);

        Q.push(R);
        temp->right = R;

        i++;
    }
    return root;
}