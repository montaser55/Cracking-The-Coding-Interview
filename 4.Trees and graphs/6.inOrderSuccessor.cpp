#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

void addChild(Node *&root, int v)
{
    Node *n = new Node(v);

    Node *x = root;
    Node *y = NULL;

    while (x != NULL)
    {
        y = x;
        if (v < x->val)
        {
            x = x->left;
        }
        else
            x = x->right;
    }

    if (y == NULL)
        root = n;
    else if (v < y->val)
    {
        y->left = n;
    }
    else
        y->right = n;
}

Node *leftMost(Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *inOrderSuccessor(Node *root, Node *n)
{
    if (n->right != NULL)
    {
        return leftMost(n->right);
    }

    Node *succ = NULL;
    while (root != NULL)
    {
        if (n->val < root->val)
        {
            succ = root;
            root = root->left;
        }
        else if (n->val > root->val)
        {
            root = root->right;
        }
        else
            break;
    }
    if (succ == NULL)
        return NULL;
    else
        return succ;
}
//inorderSuccessor with parent
// Node* inOrderSuccessor(Node* n){
//     if(n->right!=NULL)
//     {return leftMost(n->right);}
//     else{
//         Node* q=n;
//         Node* x=n.parent;
//         while(x!=NULL && x.left!=q){
//             q=x;
//             x=x.parent;
//         }
//         return x;
//     }

// }

int main()
{
    Node *root = NULL;
    addChild(root, 4);
    addChild(root, 1);
    addChild(root, 2);
    addChild(root, 3);
    addChild(root, 5);
    Node *succ = inOrderSuccessor(root, root->left->right->right);
    cout << succ->val << endl;
}