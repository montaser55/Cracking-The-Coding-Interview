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

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int listen(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
Node *findIntersection(Node *head1, Node *head2)
{
    int l1 = listen(head1);
    int l2 = listen(head2);
    Node *bigger = l1 > l2 ? head1 : head2;
    Node *smaller = l1 > l2 ? head2 : head1;
    int i = abs(l1 - l2);
    while (bigger != NULL && i--)
    {
        bigger = bigger->next;
    }

    while (bigger != NULL && smaller != NULL)
    {
        if (bigger == smaller)
            return bigger;
        bigger = bigger->next;
        smaller = smaller->next;
    }
    return NULL;
}

Node *findIntersection2(Node *head1, Node *head2)
{
    Node *l1 = head1;
    Node *l2 = head2;
    if (l1 == NULL || l2 == NULL)
        return NULL;
    while (l1 != NULL && l2 != NULL && l1 != l2)
    {
        l1 = l1->next;
        l2 = l2->next;
        if (l1 == l2)
            return l1;
        if (l1 == NULL)
            l1 = head2;
        if (l2 == NULL)
            l2 = head1;
    }
    return NULL;
}
int main()
{
    Node *head = new Node(5);
    head->next = new Node(7);
    head->next->next = new Node(10);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(9);
    Node *head2 = new Node(8);
    head2->next = new Node(2);
    head2->next->next = head->next->next->next->next;

    printList(head);
    printList(head2);

    Node *result = findIntersection(head, head2);
    if (result != NULL)
    {
        cout << "Interserction at " << result->val << "." << endl;
    }
    else
        cout << "No intersection" << endl;
    Node *result2 = findIntersection2(head, head2);
    if (result2 != NULL)
    {
        cout << "Interserction at " << result2->val << "." << endl;
    }
    else
        cout << "No intersection" << endl;
}