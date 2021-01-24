#include <bits/stdc++.h>
using namespace std;

void createMinSegmentTree(long int arr[], long int l_index, long int r_index, long int pos, long int min_seg[])
{
    if (l_index == r_index)
    {
        min_seg[pos] = arr[l_index];
        return;
    }
    long int mid = (l_index + r_index) / 2;
    createMinSegmentTree(arr, l_index, mid, 2 * pos + 1, min_seg);
    createMinSegmentTree(arr, mid + 1, r_index, 2 * pos + 2, min_seg);
    min_seg[pos] = min(min_seg[2 * pos + 1], min_seg[2 * pos + 2]);
}

long int minQuery(long int l_index, long int r_index, long int pos, long int min_seg[], long int l, long int r)
{
    if (l_index > r || r_index < l)
        return INT_MAX;
    if (l_index >= l && r_index <= r)
        return min_seg[pos];
    long int mid = (l_index + r_index) / 2;
    long int left_min = minQuery(l_index, mid, 2 * pos + 1, min_seg, l, r);
    long int right_min = minQuery(mid + 1, r_index, 2 * pos + 2, min_seg, l, r);
    return min(left_min, right_min);
}

void createMaxSegmentTree(long int arr[], long int l_index, long int r_index, long int pos, long int max_seg[])
{
    if (l_index == r_index)
    {
        max_seg[pos] = arr[l_index];
        return;
    }
    long int mid = (l_index + r_index) / 2;
    createMaxSegmentTree(arr, l_index, mid, 2 * pos + 1, max_seg);
    createMaxSegmentTree(arr, mid + 1, r_index, 2 * pos + 2, max_seg);
    max_seg[pos] = max(max_seg[2 * pos + 1], max_seg[2 * pos + 2]);
}

long int maxQuery(long int l_index, long int r_index, long int pos, long int max_seg[], long int l, long int r)
{
    if (l_index > r || r_index < l)
        return INT_MIN;
    if (l_index >= l && r_index <= r)
        return max_seg[pos];
    long int mid = (l_index + r_index) / 2;
    long int left_max = maxQuery(l_index, mid, 2 * pos + 1, max_seg, l, r);
    long int right_max = maxQuery(mid + 1, r_index, 2 * pos + 2, max_seg, l, r);
    return max(left_max, right_max);
}

int main()
{
    long int t, n, q, i, j;
    string str;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        cin >> str;
        long int arr[n], min_seg[4 * n], max_seg[4 * n];
        long int query[q][2];
        memset(arr, 0, sizeof(arr));
        if (str[0] == '-')
        {
            arr[0] = -1;
        }
        else
        {
            arr[0] = 1;
        }
        for (i = 1; i < n; i++)
        {
            if (str[i] == '-')
                arr[i] = arr[i - 1] - 1;
            else
                arr[i] = arr[i - 1] + 1;
        }

        createMinSegmentTree(arr, 0, n - 1, 0, min_seg);
        createMaxSegmentTree(arr, 0, n - 1, 0, max_seg);

        for (i = 1; i <= q; i++)
        {
            cin >> query[i][0] >> query[i][1];
        }
        for (i = 1; i <= q; i++)
        {
            long int l = query[i][0] - 1;
            long int r = query[i][1] - 1;
            long int left_min, left_max, right_min, right_max, maxm = 0, minm = 0, prev = 0;
            long int la = 0, ra = l - 1, lb = r + 1, rb = n - 1;
            if (la <= ra)
            {
                left_min = minQuery(0, n - 1, 0, min_seg, la, ra);
                left_max = maxQuery(0, n - 1, 0, max_seg, la, ra);
                minm = min(minm, left_min);
                maxm = max(maxm, left_max);
                prev = arr[ra];
            }
            if (lb <= rb)
            {
        
                right_min = minQuery(0, n - 1, 0, min_seg, lb, rb);
                right_max = maxQuery(0, n - 1, 0, max_seg, lb, rb);
                minm = min(minm, prev - arr[lb - 1] + right_min);
                maxm = max(maxm, prev - arr[lb - 1] + right_max);
            }
            cout << maxm - minm + 1 << endl;
        }
        cout << endl;
    }
}