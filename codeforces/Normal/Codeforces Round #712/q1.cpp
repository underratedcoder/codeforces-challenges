#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int

// Returns ceiling for a/b
lli my_ceil(lli a, lli b)
{
    return (a + b - 1) / b;
}

// Returns floor for a/b
lli my_floor(lli a, lli b)
{
    return a / b;
}

// #######################
// code start from here...
// #######################

int main()
{
    lli t, i, j;
    cin >> t;
    while (t--)
    {
        lli n, c = 0, pos = -1;
        string str;
        cin >> str;
        n = str.length();
        for (i = 0; i < n; i++)
        {
            if (str[i] == 'a')
                c++;
        }
        if (c == n)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (i = 0; i < n / 2; i++)
            {
                if (str[i] != str[n - i - 1])
                {
                    pos = i + 1;
                    break;
                }
            }
            for (i = 0; i < n; i++)
            {
                if (pos == i)
                {
                    cout << 'a';
                }
                cout << str[i];
                if (pos == -1 && i == n - 1)
                {
                    cout << 'a';
                }
            }
            cout << endl;
        }
    }
}
