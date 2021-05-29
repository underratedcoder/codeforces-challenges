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

int main()
{
    lli t, i, j, k;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        lli arr[n][n];
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else if (n == 2)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            k = 1;
            lli i1 = 0, j1 = 1, i2 = 1, j2 = 0;
            while (k <= n * n)
            {
                if (k <= n)
                    arr[k - 1][k - 1] = k;
                else
                {
                    if ((k - n) % 2 == 1)
                    {
                        arr[i1][j1] = k;
                        if (j1 < n - 1)
                            j1++;
                        else
                        {
                            i1++;
                            j1 = i1 + 1;
                        }
                    }
                    else
                    {
                        arr[i2][j2] = k;
                        if (j2 + 1 == i2)
                        {
                            i2++;
                            j2 = 0;
                        }
                        else
                        {
                            j2++;
                        }
                    }
                }
                k++;
            }
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}
