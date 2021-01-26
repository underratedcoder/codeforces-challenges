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
        vector<pair<lli, lli>> vec;
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            vec.push_back(make_pair(x, i));
        }
        sort(vec.begin(), vec.end());
        lli sum = 0;

        for (i = 0; i < n; i++)
        {
            if (i == 0)
                sum += vec[i].second;
            else
            {
                sum += abs(vec[i].second - vec[i - 1].second);
            }
        }
        cout << sum << endl;
    }
}