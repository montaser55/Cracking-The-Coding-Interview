#include <bits/stdc++.h>
using namespace std;

int recursiveMul(int a, int b, int adder)
{
    if (b == 1)
        return a;
    a += adder;
    b--;
    return recursiveMul(a, b, adder);
}

int mul(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    return recursiveMul(a, b, a);
}
int mulproductHelper(int smaller, int bigger)
{
    if (smaller == 0)
        return 0;
    if (smaller == 1)
        return bigger;
    int s = smaller >> 1;
    int halfside = mulproductHelper(s, bigger);
    if (smaller % 2 == 0)
        return halfside + halfside;
    else
        return halfside + halfside + bigger;
}

int mulproduct(int a, int b)
{
    int smaller = a < b ? a : b;
    int bigger = a < b ? b : a;
    return mulproductHelper(smaller, bigger);
}

int main()
{
    cout << mul(8, 7) << endl;
    cout << mulproduct(108, 10) << endl;
}
