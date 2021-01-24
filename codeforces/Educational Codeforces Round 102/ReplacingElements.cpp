#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int t, i, j, k, n, d, first, second;
    cin >> t;
    while (t--)
    {
        cin >> n >> d;
        long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i == 1)
            {
                first = min(arr[0], arr[1]);
                second = max(arr[0], arr[1]);
            }
            else if (i > 1 && arr[i] <= first)
            {
                second = first;
                first = arr[i];
            }
            else if (i > 1 && arr[i] <= second)
            {
                second = arr[i];
            }
        }
        for (i = 0; i < n; i++)
        {
            arr[i] = min(arr[i], first + second);
        }
        for (i = 0; i < n; i++)
        {
            if (arr[i] > d)
            {
                break;
            }
        }
        if (i < n)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}