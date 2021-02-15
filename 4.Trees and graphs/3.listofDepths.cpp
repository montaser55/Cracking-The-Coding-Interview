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
    Node *curr = root;
    if (root == NULL)
    {
        root = new Node(v);
        //cout<<root->val;
        return;
    }
    else if (v < root->val)
    {
        //cout << root->val;
        //curr = curr->left;
        while (curr->left != NULL && curr->val > v)
        {
            curr = curr->left;
        }
        if (v > curr->val)
        {
            curr->right = new Node(v);
        }
        else
            curr->left = new Node(v);

        return;
    }
    else if (v > root->val)
    {
        //curr = curr->right;
        while (curr->right != NULL && v > curr->val)
        {
            curr = curr->right;
        }
        if (v > curr->val)
        {
            curr->right = new Node(v);
        }
        else
            curr->left = new Node(v);

        return;
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

vector<list<Node *>> listofDepths(Node *root)
{
    vector<list<Node *>> result;
    list<Node *> parent;
    list<Node *> curr;
    if (root != NULL)
        parent.push_back(root);
    //result.push_back(parent);
    while (!parent.empty())
    {
        
        result.push_back(parent);
        
        for (auto node : parent)
        {
            if (node->left != NULL)
            {
                curr.push_back(node->left);
            }
            if (node->right != NULL)
            {
                curr.push_back(node->right);
            }
        }
        parent = curr;
        curr.clear();
        }
    return result;
}

int main()
{
    Node *root = new Node(4);
    addChild(root, 2);
    addChild(root, 1);
    addChild(root, 3);
    addChild(root, 6);
    addChild(root, 5);
    addChild(root, 7);
    preOrder(root);
    cout << endl;
    vector<list<Node *>> lists = listofDepths(root);
    for (int i = 0; i < lists.size(); i++)
    {
        cout << "level " << i + 1 << " : ";
        for (auto node : lists[i])
        {
            cout << node->val << " ";
        }
        cout << endl;
    }
}