#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

lli my_ceil(lli a, lli b)
{
    return (a + b - 1) / b;
}

// code start from here...

int main()
{
    lli t, n, m, k, i, j, x, y;
    string str;
    cin >> t;

    while (t--)
    {
        lli n, m, miss = 0, ind = -1;
        string str;
        cin >> str;
        n = str.length();
        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (str[i] == 'a')
                    str[i] = 'b';
                else
                    str[i] = 'a';
            }
            else
            {
                if (str[i] == 'z')
                    str[i] = 'y';
                else
                    str[i] = 'z';
            }
        }
        cout << str << endl;
    }
}