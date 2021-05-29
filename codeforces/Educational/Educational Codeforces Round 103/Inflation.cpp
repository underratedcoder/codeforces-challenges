#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

int main()
{
    lli t, n, k, i, j;
    cin >> t;

    while (t--)
    {

        cin >> n >> k;
        vector<double> v;
        vector<lli> pref;

        for (i = 0; i < n; i++)
        {
            double x;
            cin >> x;
            v.push_back(x);
            if (i == 0)
                pref.push_back(v[0]);
            else
            {
                pref.push_back(pref[i - 1] + v[i]);
            }
        }

        lli sum = 0;
        for (i = 1; i < n; i++)
        {
            lli minm = ceil(100 * v[i] / k);
            if (minm > pref[i - 1])
            {
                sum += (minm - pref[i - 1]);
            }
            pref[i] += sum;
        }

        cout << sum << endl;
    }
}
