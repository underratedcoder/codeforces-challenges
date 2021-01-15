#include <bits/stdc++.h>
using namespace std;

string findgcd(string s1, string s2)
{
    return (s1 + s2 == s2 + s1)
               ? s1.substr(0, gcd(size(s1), size(s2)))
               : "";
}

int main()
{
    long int t;
    string s1, s2;
    cin >> t;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        string gcd = findgcd(s1, s2);
        if (gcd == "")
            cout << "-1" << endl;
        else
        {
            int l1 = s1.length() / gcd.length();
            int l2 = s2.length() / gcd.length();

            int lcm = l1 * l2;
            for (i = 0; i < lcm; i++)
                cout << gcd;
            cout << endl;
        }
    }
}