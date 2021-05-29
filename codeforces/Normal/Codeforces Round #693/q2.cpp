#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int
lli mod = 1000000007;
#define sfor(i, a, b) for (lli i = a; i < b; i++)
#define rfor(i, a, b) for (lli i = a; i >= b; i--)
#define pb push_back
#define mp make_pair

// #######################
// code start from here...
// #######################

int main()
{
    lli t, i, j;
    cin >> t;

    while (t--)
    {
        lli n, sum = 0, c1 = 0, c2 = 0;

        cin >> n;

        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            sum += x;
            if (x == 1)
                c1++;
            else
                c2++;
        }

        if (c1 > 0 && c1 % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else if (c1 == 0 && c2 % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}