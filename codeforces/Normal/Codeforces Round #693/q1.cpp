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
        lli n, a, b;

        cin >> a >> b >> n;

        lli c1 = 1, c2 = 1;
        while (a % 2 == 0)
        {
            c1 *= 2;
            a /= 2;
        }

        while (b % 2 == 0)
        {
            c2 *= 2;
            b /= 2;
        }

        if (c1 * c2 >= n)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}