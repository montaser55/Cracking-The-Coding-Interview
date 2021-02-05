#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void insert(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->val = data;
    newNode->next = head;
    head = newNode;
}

Node *kthfromLast(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    Node *fast = head;
    Node *slow = head;
    while (k--)
    {
        if (fast != NULL)
            fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node *recursiveHelper(Node *head, int k, int &i)
{
    if (head == NULL)
        return NULL;
    Node *n = recursiveHelper(head->next, k, i);
    i = i + 1;
    if (i == k)
        return head;
    return n;
}

Node *kthfromLastRecursive(Node *head, int k)
{
    int i=0;    
    return recursiveHelper(head, k, i);
}

int main()
{
    Node *head = NULL;
    insert(head, 7);
    insert(head, 4);
    insert(head, 6);
    insert(head, 9);
    insert(head, 1);
    insert(head, 3);
    insert(head, 8);
    printList(head);
    Node *kth = kthfromLast(head, 4);
    if (kth != NULL)
    {
        cout << kth->val << endl;
    }
    else
        cout << "NULL" << endl;

    Node *kthnew = kthfromLastRecursive(head, 4);
    if (kthnew != NULL)
    {
        cout << kthnew->val << endl;
    }
    else
        cout << "NULL" << endl;
}
