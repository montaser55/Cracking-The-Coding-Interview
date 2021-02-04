#include <bits/stdc++.h>
using namespace std;

int charval(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A';
    else
        return -1;
}
bool checkPermu(string s)
{
    int check[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int temp = charval(s[i]);
        if (temp != -1)
        {
            check[temp]++;
        }
    }
    bool oneOdd = false;
    for (int i = 0; i < 26; i++)
    {
        if (check[i] % 2 != 0)
        {
            if (oneOdd)
                return false;
            else
                oneOdd = true;
        }
    }
    return true;
}

int main()
{
    cout << boolalpha << checkPermu("Tact Coa")<<endl;
    cout << boolalpha << checkPermu("Tact Doa");
}