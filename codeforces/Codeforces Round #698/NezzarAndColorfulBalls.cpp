#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

int main()
{
    lli t, n, k, i;
    cin >> t;

    while (t--)
    {
        cin >> n;
        lli arr[101];
        memset(arr, 0, sizeof(arr));
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            // v.push_back(x);
            arr[x] = arr[x] + 1;
        }

        lli maxm = 0;
        for (i = 1; i <= n; i++)
        {
            maxm = max(maxm, arr[i]);
        }
        cout << maxm << endl;
    }
}