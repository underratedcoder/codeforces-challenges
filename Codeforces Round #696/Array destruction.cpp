#include <bits/stdc++.h>
using namespace std;
 
int fun(long int arr[], long int n, unordered_map<long int, long int> umap, long int start, vector<pair<long int, long int>> &vect)
{
    int del = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (umap[arr[i]])
        {
            if (umap[start])
            {
                umap[start]--;
            }
            long int latest = start - arr[i];
            // cout << "i: " << i << " start: " << start << " arr[i]: " << arr[i] << " latest: " << latest << " umap[arr[i]]: " << umap[arr[i]] << endl;
            // // cout << latest << " " << i << " " << start << " " << arr[i] << endl;
            if (!umap[latest])
            {
                return 0;
            }
            if (umap[latest] == 1 && latest == arr[i])
            {
                return 0;
            }
            umap[arr[i]]--;
            umap[latest]--;
            del--;
            del--;
            vect.push_back(make_pair(arr[i], latest));
            if (del == 0)
                break;
 
            // for (int k = 0; k < n; k++)
            // {
            //     cout << arr[k] << " " << umap[arr[k]] << " ";
            // }
            // cout << endl;
            // cout << "del : " << del;
            start = arr[i];
        }
    }
    return 1;
}
 
int main()
{
    long int t, i, j, k, n, x, l, sum;
    cin >> t;
    while (t--)
    {
        cin >> n;
        n = 2 * n;
        long int arr[n];
        unordered_map<long int, long int> umap;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
            umap[arr[i]]++;
        }
        sort(arr, arr + n);
        for (i = 0; i < n - 1; i++)
        {
            vector<pair<long int, long int>> vect;
            if (fun(arr, n, umap, arr[i] + arr[n - 1], vect))
            {
                cout << "YES" << endl;
                cout << arr[i] + arr[n - 1] << endl;
                for (int j = 0; j < vect.size(); j++)
                {
                    cout << vect[j].first << " " << vect[j].second << endl;
                }
                break;
            }
        }
        if (i == n - 1)
        {
            cout << "NO" << endl;
        }
    }
}