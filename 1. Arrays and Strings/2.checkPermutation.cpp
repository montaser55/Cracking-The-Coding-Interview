#include <bits/stdc++.h>
using namespace std;

bool isPermutation1(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int charval(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A';

    return -1;
}

bool isPermutation2(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    int check[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int temp = charval(s1[i]);
        if (temp != -1)
        {
            check[temp]++;
        }
    }

    for (int i = 0; i < s2.length(); i++)
    {
        int temp = charval(s2[i]);
        if (temp != -1)
        {
            if (--check[temp] < 0)
                return false;
        }
    }
    return true;
}

int main()
{
    cout << boolalpha << isPermutation1("ABCDE", "EDCBA") << endl;
    cout << boolalpha << isPermutation1("ABCD", "CBA") << endl;
    cout << boolalpha << isPermutation2("ABCDE", "EDCBA") << endl;
    cout << boolalpha << isPermutation2("ABCD", "CBA") << endl;
}