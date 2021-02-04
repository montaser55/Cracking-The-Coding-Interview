#include <bits/stdc++.h>
using namespace std;

string urlify(string s, int n)
{
    int spacecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            spacecount++;
    }
    int newcount = n + 2 * spacecount;
    int i = newcount - 1;
    for (int j = n - 1; j >= 0; j--)
    {
        if (s[j] == ' ')
        {
            s[i--] = '0';
            s[i--] = '2';
            s[i--] = '%';
        }
        else
        {
            s[i--] = s[j];
        }
    }
    return s;
}

int main()
{
    cout << urlify("Mr John Smith    ", 13) << endl;
}