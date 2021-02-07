#include <bits/stdc++.h>
using namespace std;

int bitSwapReq(int a, int b)
{
    int c = a ^ b;
    int count = 0;
    while (c != 0)
    {
        count++;
        c = c & (c - 1);
    }
    return count;
}

int main()
{
    cout << bitSwapReq(0b11101, 0b01111);
}