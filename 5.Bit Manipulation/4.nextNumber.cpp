#include <bits/stdc++.h>
using namespace std;

void decToBin(int n)
{
    for (int i = 31; i >= 0; i--)
    {
        if (n >> i & 1)
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}

int nextNumber(int n)
{
    int result;
    int c0 = 0, c1 = 0;
    int temp = n;
    while ((temp & 1) == 0 && (temp != 0))
    {
        c0++;
        temp = temp >> 1;
    }

    while ((temp & 1) == 1)
    {
        c1++;
        temp = temp >> 1;
    }

    if (c0 + c1 == 31 || c0 + c1 == 0)
        return -1;

    n |= (1 << c0 + c1);
    n &= ~((1 << c0 + c1) - 1);
    n |= (1 << c1 - 1) - 1;
    return n;
}

int prevNumber(int n)
{
    int temp = n;
    int c0 = 0, c1 = 0;

    while ((temp & 1) == 1)
    {
        c1++;
        temp = temp >> 1;
    }

    if (temp == 0)
        return -1;

    while ((temp & 1) == 0 && temp != 0)
    {
        c0++;
        temp = temp >> 1;
    }

    n &= (~0) << (c0 + c1 + 1);
    int mask = (1 << c1 + 1) - 1;
    n |= mask << c0 - 1;
    return n;
}

int main()
{
    int result = nextNumber(0b11011001111100);
    decToBin(result);
    result = prevNumber(0b11011001111100);
    decToBin(result);
}
