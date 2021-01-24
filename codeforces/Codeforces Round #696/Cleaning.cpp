#include <bits/stdc++.h>
using namespace std;

int check(vector<long int> a, long int n)
{
    for (int i = 0; i + 1 < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0;
        }
        a[i + 1] -= a[i];
        a[i] = 0;
    }
    if (a[n - 1] == 0)
        return 1;
    return 0;
}

int main()
{
    long int t, i, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<long int> arr;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            arr.push_back(x);
        }
        if (n == 2)
        {
            if (arr[0] == arr[1])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }

        if (check(arr, n))
        {
            cout << "YES" << endl;
            continue;
        }
        swap(arr[0], arr[1]);
        if (check(arr, n))
        {
            cout << "YES" << endl;
            continue;
        }
        swap(arr[0], arr[1]);
        swap(arr[n - 1], arr[n - 2]);
        if (check(arr, n))
        {
            cout << "YES" << endl;
            continue;
        }
        swap(arr[n - 1], arr[n - 2]);

        long int pref[n], suff[n];
        pref[0] = arr[0];
        suff[n - 1] = arr[n - 1];
        for (i = 1; i < n; i++)
        {
            pref[i] = arr[i] - pref[i - 1];
            suff[n - i - 1] = arr[n - i - 1] - suff[n - i];
        }
        for (i = 1; i < n - 2; i++)
        {
            if (arr[i + 1] - pref[i - 1] == arr[i] - suff[i + 2])
            {
                cout << "YES" << endl;
                break;
            }
        }
        if (i == n - 2)
        {
            cout << "NO" << endl;
        }
    }
}
