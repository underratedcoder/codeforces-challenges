#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int

lli power(lli a, lli b)
{
    lli ans = 1;
    a = a;
    while (b)
    {
        if (b & 1)
            ans = (ans * a);
        b /= 2;
        a = (a * a);
    }
    return ans;
}

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
        lli n, k, b = 0;
        cin >> n;
        k = n;
        while (k > 0)
        {
            k /= 2;
            b++;
        }
        cout << power(2, (b - 1)) - 1 << endl;
    }
}
