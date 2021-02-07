#include <bits/stdc++.h>
using namespace std;

void dectoBin(int n)
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

int pairswap(int x){
    return (x & 0xaaaaaaaa)>>1|(x & 0x55555555)<<1;
}

int main()
{
    int res = pairswap(0b10101010101010101010001010111010);
    dectoBin(res);
}