#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

int main()
{
    lli t, n, i, j, ok;
    cin >> t;

    while (t--)
    {
        cin >> n;
        ok = 0;
        while (n >= 2020)
        {

            if (n % 2020 == 0 || n % 2021 == 0)
            {
                ok = 1;
                break;
            }
            n = n - 2021;
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}