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

        cin >> n >> k;

        lli cnt = 0;
        for (i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (n / i == i)
                {

                    if (i & (1 << (k - 1)))
                        cnt++;
                }
                else
                {
                    if (i & (1 << (k - 1)))
                        cnt++;
                    if ((n / i) & (1 << (k - 1)))
                        cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}