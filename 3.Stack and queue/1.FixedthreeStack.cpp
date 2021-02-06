#include <bits/stdc++.h>
using namespace std;

class FixedThreeStack
{
    int numberofStacks = 3;
    int stackCapacity;
    int *values;
    int sizes[3] = {0};

public:
    FixedThreeStack(int cap)
    {
        stackCapacity = cap;
        values = new int[stackCapacity * numberofStacks];
    }

    bool isFull(int stackNum)
    {

        if (stackNum < 3)
            return sizes[stackNum] == stackCapacity;
        else
            return true;
    }

    bool isEmpty(int stackNum)
    {
        if (stackNum < 3)
            return sizes[stackNum] == 0;
        else
            return true;
    }

    int indexOfTop(int stackNum)
    {
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size - 1;
    }

    void push(int stackNum, int val)
    {
        if (isFull(stackNum))
        {
            cout << "Stack is Full" << endl;
        }
        else
        {
            sizes[stackNum]++;
            values[indexOfTop(stackNum)] = val;
            cout << "Pushed " << val << " in Stack " << stackNum + 1 << endl;
        }
    }

    void pop(int stackNum)
    {
        int temp = INT_MIN;
        if (isEmpty(stackNum))
            cout << "Stack is empty." << endl;
        else
        {
            int index = indexOfTop(stackNum);
            //temp = values[index];
            values[index] = 0;
            sizes[stackNum]--;
        }
        return;
    }

    int top(int stackNum)
    {
        if (isEmpty(stackNum))
        {
            cout << "Empty stack" << endl;
            return INT_MIN;
        }
        else
            return values[indexOfTop(stackNum)];
    }

    ~FixedThreeStack()
    {
        delete[] values;
    }
};

int main()
{
    FixedThreeStack fs(10);
    fs.push(0, 1);
    fs.push(0, 2);
    fs.push(0, 10);
    fs.push(0, 7);
    fs.push(1, 5);
    fs.push(1, 12);
    fs.push(2, 5);
    fs.push(2, 50);
    fs.push(2, 15);
    cout << fs.top(0) << endl;
    fs.pop(0);
    cout << fs.top(0) << endl;
    fs.pop(0);
    cout << fs.top(1) << endl;
    fs.pop(1);
    cout << fs.top(2) << endl;
    fs.pop(2);
}