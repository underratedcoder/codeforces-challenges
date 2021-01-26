#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

int main()
{
    lli t, n, r, i;
    cin >> t;

    while (t--)
    {
        cin >> r;
        cin >> n;
        lli arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (i = 0; i < n; i++)
        {
            if (arr[i] >= r)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}