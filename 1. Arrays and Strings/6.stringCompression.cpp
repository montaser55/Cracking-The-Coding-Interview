#include <bits/stdc++.h>
using namespace std;

string stringCompression(string s)
{
    if (s.length() < 2)
        return s;
    string result = "";
    int count = 1;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            result += s[i];
            result += to_string(count);
            count = 1;
        }
        else
            count++;
    }
    result += s[s.length() - 1];
    result += to_string(count);
    if (result.length() >= s.length())
        return s;
    else
        return result;
}
int main()
{
    cout << stringCompression("aabbbcceee") << endl;
    cout << stringCompression("abc") << endl;
}