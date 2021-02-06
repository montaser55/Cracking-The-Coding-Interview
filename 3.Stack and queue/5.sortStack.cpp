#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &s)
{
    stack<int> sorted;
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        while (!sorted.empty() && temp < sorted.top())
        {
            s.push(sorted.top());
            sorted.pop();
        }
        sorted.push(temp);
    }
    while (!sorted.empty())
    {
        s.push(sorted.top());
        sorted.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(7);
    s.push(10);
    s.push(100);
    s.push(8);
    s.push(50);
    s.push(29);
    sortStack(s);
    for (int i = 0; i < 7; i++)
    {
        cout << "top-->" << s.top() << endl;
        s.pop();
    }
}