#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

int main()
{
    lli t, n, k, i, j;
    string str;
    cin >> t;

    while (t--)
    {

        cin >> n;
        cin >> str;

        lli L1[n + 1], L2[n + 1], R1[n + 1], R2[n + 1];
        for (i = 0; i <= n; i++)
        {
            L1[i] = L2[i] = R1[i] = R2[i] = 1;
        }

        for (i = 0; i < n; i++)
        {
            if (str[i] == 'L')
            {
                L1[i + 1] = 1 + L2[i];
            }
            else
            {
                L2[i + 1] = 1 + L1[i];
            }
        }

        for (i = n - 1; i >= 0; i--)
        {
            if (str[i] == 'R')
            {
                R1[i] = 1 + R2[i + 1];
            }
            else
            {
                R2[i] = 1 + R1[i + 1];
            }
        }

        for (i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                cout << R1[i] << " ";
            }
            else if (i == n)
            {
                cout << L1[i] << " ";
            }
            else
            {
                if (str[i - 1] == 'L' && str[i] == 'R')
                {
                    cout << L1[i] + R1[i] - 1 << " ";
                }
                else if (str[i - 1] == 'L')
                {
                    cout << L1[i] << " ";
                }
                else if (str[i] == 'R')
                {
                    cout << R1[i] << " ";
                }
                else
                {
                    cout << 1 << " ";
                }
            }
        }
        cout << endl;
    }
}