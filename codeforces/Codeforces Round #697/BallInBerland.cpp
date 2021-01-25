#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

int main()
{
    lli t, n, i, j, a, b, k;
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> k;

        lli arr[k], brr[k];

        unordered_map<lli, lli> first;
        unordered_map<lli, lli> second;

        for (i = 0; i < k; i++)
        {
            cin >> arr[i];
            first[arr[i]]++;
        }
        for (i = 0; i < k; i++)
        {
            cin >> brr[i];
            second[brr[i]]++;
        }

        lli ans = 0;
        for (i = 0; i < k; i++)
        {
            lli c1 = first[arr[i]];
            lli c2 = second[brr[i]];
            ans = ans + k - (c1 + c2 - 1);
        }
        cout << ans/2 << endl;
    }
}