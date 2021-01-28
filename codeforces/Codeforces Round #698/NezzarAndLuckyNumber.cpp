#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

int main()
{
    lli t, n, k, d, i;
    cin >> t;

    while (t--)
    {
        cin >> n >> d;
        vector<lli> v;
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            v.push_back(x);
        }

        for (i = 0; i < n; i++)
        {

            if (v[i] >= d * 10)
                cout << "YES" << endl;
            else
            {

                lli ok = 0;
                for (lli j = 1; j <= 9; j++)
                {
                    lli newD = d * j;
                    if (newD <= v[i] && newD % 10 == v[i] % 10)
                    {
                        ok = 1;
                        break;
                    }
                }
                if (ok)
                    cout << "YES" << endl;
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }
}