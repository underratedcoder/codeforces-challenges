#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int t, i, j, n, m, x, l, minm, sw, si, dw, di;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        char mat[n][m];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
                cin >> mat[i][j];
        }
        minm = 0;
        sw = si = dw = di = 0;
        if (n % 2 == 1 && m % 2 == 1)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
                    {
                        if (mat[i][j] == '.')
                        {
                            minm++;
                        }
                    }
                    else
                    {

                        if (mat[i][j] == '*')
                        {
                            minm++;
                        }
                    }
                }
            }
            cout << minm << endl;
            continue;
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
                    {
                        if (mat[i][j] == '.')
                        {
                            sw++;
                        }
                        else
                        {
                            si++;
                        }
                    }
                    else
                    {
                        if (mat[i][j] == '.')
                        {
                            dw++;
                        }
                        else
                        {
                            di++;
                        }
                    }
                }
            }
        }
        cout << min((n * m / 2) - si + (n * m / 2) - dw, (n * m / 2) - di + (n * m / 2) - sw) << endl;
    }
}