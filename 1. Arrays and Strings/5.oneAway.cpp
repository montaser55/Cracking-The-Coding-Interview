#include <bits/stdc++.h>
using namespace std;

bool oneaway(string s1, string s2)
{
    string smaller = s1.length() > s2.length() ? s2 : s1;
    string bigger = s1.length() > s2.length() ? s1 : s2;

    if ((bigger.length() - smaller.length()) > 1)
        return false;
    bool oneMismatch = false;
    for (int i = 0, j = 0; i < bigger.length();)
    {
        if (bigger[i] != smaller[j])
        {
            if (oneMismatch)
                return false;
            if (s1.length() == s2.length())
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
            oneMismatch = true;
        }
        else
        {
            i++;
            j++;
        }
    }
    return true;
}
int main()
{
    cout << boolalpha << oneaway("pale", "bale") << endl;
    cout << boolalpha << oneaway("pale", "bal") << endl;
    cout << boolalpha << oneaway("pale", "nale") << endl;
    cout << boolalpha << oneaway("pale", "ble") << endl;
}