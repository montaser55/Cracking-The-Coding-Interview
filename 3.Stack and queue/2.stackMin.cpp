#include <bits/stdc++.h>
using namespace std;

class stackWithMin
{
    stack<int> s1, s2;

public:
    void push(int v)
    {
        if (s2.empty() || v <= s2.top())
        {
            s1.push(v);
            s2.push(v);
        }
        else
        {
            s1.push(v);
        }
    }

    void pop()
    {
        if (s1.empty())
            cout << "Stack Empty" << endl;
        else
        {
            if ((!s2.empty()) && s1.top() == s2.top())
            {
                s1.pop();
                s2.pop();
            }
            else
            {
                s1.pop();
            }
        }
    }

    int stackMin()
    {
        if (!s2.empty())
            return s2.top();
        return INT_MIN;
    }

    bool isEmpty()
    {
        if (s1.empty())
            return true;
        else
            return false;
    }

    int top()
    {
        return s1.top();
    }
};

int main()
{
    stackWithMin s;
    s.push(9);
    s.push(10);
    s.push(7);
    s.push(8);
    s.push(6);
    s.push(2);
    s.push(1);
    s.push(50);
    cout << s.stackMin() << endl;
    s.pop();
    cout << s.stackMin() << endl;
    s.pop();
    cout << s.stackMin() << endl;
    s.pop();
    cout << s.stackMin() << endl;
    s.pop();
    cout << s.stackMin() << endl;
    s.pop();
    cout << s.stackMin() << endl;
    s.pop();
    cout << "top-->" << s.top() << endl;
    cout << s.stackMin() << endl;
    s.pop();
    cout << "top-->" << s.top() << endl;
    cout << s.stackMin() << endl;
    s.pop();
    cout << "top-->" << s.top() << endl;
    cout << s.stackMin() << endl;
    s.pop();
}