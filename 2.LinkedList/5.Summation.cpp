#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val = 0;
    Node *next = NULL;
    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

void insert(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
        head = newNode;
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

Node *summation(Node *head1, Node *head2)
{
    Node *result = new Node(0);
    Node *curr = result;
    int sum = 0;
    int carry = 0;
    while (head1 != NULL || head2 != NULL)
    {
        sum = carry;
        if (head1 != NULL)
        {
            sum += head1->val;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            sum += head2->val;
            head2 = head2->next;
        }
        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
    }
    if (carry > 0)
    {
        curr->next = new Node(1);
    }
    return result->next;
}

int main()
{
    Node *head1 = NULL;
    insert(head1, 2);
    insert(head1, 6);
    insert(head1, 9);
    printList(head1);
    Node *head2 = NULL;
    insert(head2, 9);
    insert(head2, 5);
    insert(head2, 9);
    printList(head2);
    Node *head3 = summation(head1, head2);
    printList(head3);
}