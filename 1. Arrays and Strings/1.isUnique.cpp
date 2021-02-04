#include <bits/stdc++.h>
using namespace std;

bool isUnique1(string s)
{
    vector<bool> check(128, false);
    if (s.length() > 128)
        return false;

    for (int i = 0; i < s.length(); i++)
    {
        int temp = s[i];
        if (check[temp])
            return false;
        else
            check[temp] = true;
    }
    return true;
}

bool isUnique2(string s)
{
    if (s.length() > 128)
        return false;
    bitset<256> bits(0);
    for (int i = 0; i < s.length(); i++)
    {
        int temp = s[i];
        if (bits.test(temp) == 1)
            return false;
        else
            bits.set(temp);
    }
    return true;
}

bool isUnique3(string s)
{
    sort(s.begin(), s.end());
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
            return false;
    }
    return true;
}
int main()
{
    cout << boolalpha << isUnique1("ABC") << endl;
    cout << boolalpha << isUnique1("ABBC") << endl;
    cout << boolalpha << isUnique2("ABC") << endl;
    cout << boolalpha << isUnique2("ABBC") << endl;
    cout << boolalpha << isUnique3("ABC") << endl;
    cout << boolalpha << isUnique3("ABBC") << endl;
}
