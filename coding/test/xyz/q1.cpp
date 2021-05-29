#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int

int main()
{
    lli t, i, j, n, m;
    // cin >> t;
    // while (t--)
    // {
    int maxSize = 10000, maxm = -1;
    vector<vector<lli>> vec1{{1, 3000}, {2, 5000}, {3, 5000}, {4, 10000}};
    vector<vector<lli>> vec2{{1, 2000}, {2, 4000}, {3, 4000}};
    vector<vector<lli>> ans;
    n = vec1.size();
    m = vec2.size();
    cout << n << " " << m << endl;
    vector<pair<lli, lli>> v1, v2;
    for (i = 0; i < n; i++)
    {
        v1.push_back({vec1[i][1], vec1[i][0]});
    }
    for (i = 0; i < m; i++)
    {
        v2.push_back({vec2[i][1], vec2[i][0]});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (v1[i].first + v2[j].first == maxSize)
        {
            maxm = maxSize;
            break;
            // vector<lli> temp;
            // temp.push_back(v1[i].second);
            // temp.push_back(v2[j].second);
            // ans.push_back(temp);
            // i++;
            // j--;
        }
        else if (v1[i].first + v2[j].first < maxSize)
        {
            if (v1[i].first + v2[j].first > maxm)
                maxm = v1[i].first + v2[j].first;
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "maxm : " << maxm << endl;

    i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (v1[i].first + v2[j].first == maxm)
        {
            vector<lli> temp;
            temp.push_back(v1[i].second);
            temp.push_back(v2[j].second);
            ans.push_back(temp);
            i++;
            j--;
        }
        else if (v1[i].first + v2[j].first < maxSize)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    // for (i = 0; i < n; i++)
    // {
    //     cout << v1[i].first << " " << v1[i].second << endl;
    // }

    // for (i = 0; i < m; i++)
    // {
    //     cout << v2[i].first << " " << v2[i].second << endl;
    // }
    cout << "###############################" << endl;
    // }
}