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

bool checkPalindrome1(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *fast = head;
    Node *slow = head;
    stack<int> s;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        s.push(slow->val);
        slow = slow->next;
    }
    if (fast != NULL && fast->next == NULL)
        slow = slow->next;
    while (!s.empty() && slow != NULL)
    {
        if (slow->val != s.top())
            return false;
        s.pop();
        slow = slow->next;
    }

    return true;
}

void reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

bool checkPalindrome2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *fast = head;
    Node *slow = head;
    Node *mid = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast != NULL && fast->next == NULL)
    {
        slow = slow->next;
    }

    reverse(slow);

    fast = head;
    mid = slow;
    while (slow != NULL && fast != NULL && slow->val == fast->val)
    {
        slow = slow->next;
        fast = fast->next;
    }
    reverse(mid);
    if (slow == NULL)
        return true;
    else
        return false;
}

bool checkPalindromeHelper(Node *&left, Node *right)
{
    if (right == NULL)
        return true;
    bool isPalindrome = checkPalindromeHelper(left, right->next);
    if (!isPalindrome)
        return false;
    if (left->val == right->val)
        isPalindrome = true;
    else
        isPalindrome = false;
    left = left->next;
    return isPalindrome;
}

bool checkPalindromeRec(Node *head)
{
    return checkPalindromeHelper(head, head);
}

int main()
{
    Node *head = NULL;
    insert(head, 7);
    insert(head, 2);
    insert(head, 9);
    insert(head, 7);
    insert(head, 9);
    insert(head, 2);
    insert(head, 7);
    printList(head);
    cout << boolalpha << checkPalindrome1(head) << endl;
    cout << boolalpha << checkPalindrome2(head) << endl;
    cout << boolalpha << checkPalindromeRec(head) << endl;
}