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
    {
        root = n;
    }
    else if (v < y->val)
    {
        y->left = n;
    }
    else
        y->right = n;

    return;
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool checkBalanced(Node *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1 && checkBalanced(root->left) && checkBalanced(root->right))
    {
        return true;
    }
    return false;
}

int main()
{
    Node *root = NULL;
    addChild(root, 4);
    addChild(root, 2);
    addChild(root, 1);
    addChild(root, 3);
    addChild(root, 6);
    addChild(root, 5);
    addChild(root, 7);
    preOrder(root);
    cout << endl;
    cout << boolalpha << checkBalanced(root) << endl;

    Node *root2 = NULL;
    addChild(root2, 4);
    addChild(root2, 6);
    addChild(root2, 8);
    addChild(root2, 9);
    addChild(root2, 5);
    addChild(root2, 10);
    addChild(root2, 19);
    preOrder(root2);
    cout << endl;
    cout << boolalpha << checkBalanced(root2) << endl;
}