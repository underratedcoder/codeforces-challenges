#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int t, n, k, i;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int m = 2 * n - 2 * k + 1;
        for (i = 1; i <= n - m; i++)
        {
            cout << i << " ";
        }
        for (i = k; i > n - m; i--)
        {
            cout << i << " ";
        };
        cout << endl;
    }
}