#include <bits/stdc++.h>
using namespace std;

void permutaionWithDupsHelper(string curr, unordered_map<char, int> m, vector<string> &result, int n)
{
    if (curr.length() == n)
    {
        result.push_back(curr);
        return;
    }
    for (auto i : m)
    {
        if (i.second != 0)
        {
            m[i.first]--;
            permutaionWithDupsHelper(curr + i.first, m, result, n);
            m[i.first]++;
        }
    }
}

vector<string> permutationWithDups(string a)
{
    vector<string> result;
    unordered_map<char, int> m;
    for (int i = 0; i < a.length(); i++)
    {
        m[a[i]]++;
    }
    permutaionWithDupsHelper("", m, result, a.length());
    return result;
}

int main()
{
    string a = "aaabb";
    vector<string> result = permutationWithDups(a);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}