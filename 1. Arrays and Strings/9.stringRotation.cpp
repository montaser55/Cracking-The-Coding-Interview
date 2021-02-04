#include <bits/stdc++.h>
using namespace std;

bool checkRotation(string s1, string s2)
{
    string temp = s2 + s2;
    if (temp.find(s1) != string::npos)
        return true;
    return false;
}

int main()
{
    cout << boolalpha << checkRotation("programming", "mingprogram") << endl;
    cout << boolalpha << checkRotation("programming", "mingprogra");
}