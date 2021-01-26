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
        vector<lli> v;
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            v.push_back(x);
        }

        lli maxm = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] == 1)
            {
                lli sum = 1;
                i++;
                while (i < n && v[i] == v[i - 1] + 1)
                {
                    sum++;
                    i++;
                }
                i--;
                maxm = max(maxm, sum);
            }
        }
        cout << maxm << endl;
    }
}