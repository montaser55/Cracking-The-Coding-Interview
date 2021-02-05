#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val = 0;
    Node *next;
    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
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

Node *partition(Node *head, int x)
{
    Node *l1 = new Node(0), *l2 = new Node(0);
    Node *p1 = l1, *p2 = l2, *p = head;
    while (p != NULL)
    {
        if (p->val < x)
        {
            p1->next = p;
            p1 = p1->next;
        }
        else
        {
            p2->next = p;
            p2 = p2->next;
        }
        p = p->next;
    }
    p2->next = NULL;
    p1->next = l2->next;
    return l1->next;
}
int main()
{
    Node *head = NULL;
    insert(head, 7);
    insert(head, 1);
    insert(head, 2);
    insert(head, 8);
    insert(head, 10);
    insert(head, 2);
    insert(head, 5);
    printList(head);
    head=partition(head,5);
    printList(head);
}