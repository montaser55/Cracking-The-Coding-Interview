#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val = 0;
    Node *next = NULL;
};

void insert(Node *&head, int val)
{
    Node *newNode = new Node;
    newNode->val = val;
    newNode->next = head;
    head = newNode;
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

Node *deleteMiddleNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *dummy = new Node;
    dummy->next = head;
    Node *curr = dummy->next;
    Node *prev = dummy;
    while (curr != NULL && curr->next != NULL)
    {
        curr = curr->next->next;
        prev = prev->next;
    }
    prev->next = prev->next->next;
    return dummy->next;
}

int main()
{
    Node *head = NULL;
    insert(head, 7);
    insert(head, 2);
    insert(head, 3);
    insert(head, 1);
    insert(head, 8);
    insert(head, 6);
    insert(head, 10);
    printList(head);
    head = deleteMiddleNode(head);
    printList(head);
    Node *head2 = NULL;
    insert(head2, 7);
    insert(head2, 2);
    insert(head2, 5);
    printList(head2);
    head2 = deleteMiddleNode(head2);
    printList(head2);
}