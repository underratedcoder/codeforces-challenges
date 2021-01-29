#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli unsigned long long int

int main()
{
    lli t, i, j;
    cin >> t;

    while (t--)
    {
        double n, k;
        cin >> n >> k;

        if (n > k)
        {
            cout << ceil((ceil(n / k) * k) / n) << endl;
        }
        else
        {
            cout << ceil(k / n) << endl;
        }
    }
}