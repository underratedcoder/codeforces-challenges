#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int t, i, j, n, m, x, l, minm, sw, si, dw, di;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (str.length() < 10)
        {
            cout << "NO" << endl;
            continue;
        }
        int sm = 0, cp = 0, sp = 0, dg = 0;
        for (i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                sm++;
        }
        for (i = 1; i < str.length() - 1; i++)
        {

            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                cp++;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                dg++;
            }
            else if (str[i] == '#' || str[i] == '%' || str[i] == '&' || str[i] == '@' || str[i] == '?')
            {
                sp++;
            }
        }
        if (sm && cp && dg && sp)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}