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

void createBST(Node *&root, int arr[], int start, int end)
{
    if (start > end)
        return;
    if (root == NULL)
    {
        int mid = start + (end - start) / 2;
        root = new Node(arr[mid]);
        createBST(root->left, arr, start, mid - 1);
        createBST(root->right, arr, mid + 1, end);
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

bool validateBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->val < min || root->val > max)
    {
        return false;
    }
    if (validateBST(root->left, min, root->val) && validateBST(root->right, root->val, max))
        return true;
    else
    {
        return false;
    }
}

int main()
{
    Node *root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    createBST(root, arr, 0, 8);
    preOrder(root);
    cout << endl;
    cout << boolalpha << validateBST(root, INT_MIN, INT_MAX) << endl;
    Node *root2 = NULL;
    int arr2[] = {1, 2, 3, 4, 25, 6, 7, 8, 9};
    createBST(root2, arr2, 0, 8);
    preOrder(root2);
    cout << endl;
    cout << boolalpha << validateBST(root2, INT_MIN, INT_MAX) << endl;
}