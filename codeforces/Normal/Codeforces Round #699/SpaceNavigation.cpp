#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

// code start from here...

int main()
{
    lli t, n, m, k, i, j, x, y;
    string str;
    cin >> t;

    while (t--)
    {
        lli n;
        cin >> x >> y;
        cin >> str;
        n = str.length();

        lli u = 0, r = 0, l = 0, d = 0, ok = 0;

        for (i = 0; i < n; i++)
        {
            if (str[i] == 'U')
                u++;
            else if (str[i] == 'R')
                r++;
            else if (str[i] == 'D')
                d++;
            else if (str[i] == 'L')
                l++;
        }
        if (x >= 0 && y >= 0 && u >= y && r >= x)
        {
            ok = 1;
        }

        if (x <= 0 && y >= 0 && u >= y && l >= abs(x))
        {
            ok = 1;
        }

        if (x >= 0 && y <= 0 && d >= abs(y) && r >= x)
        {
            ok = 1;
        }

        if (x <= 0 && y <= 0 && d >= abs(y) && l >= abs(x))
        {
            ok = 1;
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}