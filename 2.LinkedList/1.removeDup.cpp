#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val = 0;
    Node *next = NULL;
};

void insert(Node *&head, int data)
{
    Node *newnode = new Node;
    newnode->val = data;
    newnode->next = head;
    head = newnode;
}

Node *removeDups(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    unordered_set<int> s;
    Node *curr = head->next;
    Node *prev = head;
    s.insert(prev->val);
    while (curr != NULL)
    {
        while (curr != NULL && s.find(curr->val) != s.end())
        {
            curr = curr->next;
        }
        prev->next = curr;
        prev = curr;
        if (curr != NULL)
        {
            s.insert(curr->val);
            curr = curr->next;
        }
    }
    return head;
}

Node *removeDupWithoutBuffer(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *Runnable = curr;
        while (Runnable->next != NULL)
        {
            if (curr->val == Runnable->next->val)
            {
                Runnable->next = Runnable->next->next;
            }
            else
            {
                Runnable = Runnable->next;
            }
        }
        curr = curr->next;
    }
    return head;
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

int main()
{
    Node *head = NULL;
    insert(head, 2);
    insert(head, 7);
    insert(head, 4);
    insert(head, 2);
    insert(head, 4);
    insert(head, 1);
    printList(head);
    head = removeDupWithoutBuffer(head);
    printList(head);
}
