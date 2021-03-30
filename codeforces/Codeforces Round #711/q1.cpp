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
lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    lli t, i, j;
    cin >> t;
    while (t--)
    {
        lli n, m;
        cin >> n;
        while (n)
        {
            lli sum = 0, temp = n;
            while (temp > 0)
            {
                sum += temp % 10;
                temp /= 10;
            }

            lli ans = gcd(n, sum);
            if (ans > 1)
                break;
            n++;
        }
        cout << n << endl;
    }
}
