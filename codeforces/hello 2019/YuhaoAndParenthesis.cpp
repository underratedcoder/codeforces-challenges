#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define st string

int main()
{
    li n, i, j;
    cin >> n;
    vector<string> str;
    for (i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str.push_back(s);
    }
    li ans = 0;
    li correct = 0;
    unordered_map<li, li> left;
    unordered_map<li, li> right;
    for (i = 0; i < n; i++)
    {
        stack<char> stk;
        li lt = 0, rt = 0;
        for (j = 0; j < str[i].length(); j++)
        {
            if (str[i][j] == '(')
            {
                lt++;
            }
            else if (str[i][j] == ')')
            {
                if (lt > 0)
                {
                    lt--;
                }
                else
                {
                    rt++;
                }
            }
        }
        if (!lt && !rt)
            correct++;
        else if (lt && !rt)
        {
            if (right[lt])
            {
                ans++;
                right[lt]--;
            }
            else
            {
                left[lt]++;
            }
        }
        else if (!lt && rt)
        {
            if (left[rt])
            {
                ans++;
                left[rt]--;
            }
            else
            {
                right[rt]++;
            }
        }
    }
    cout << ans + correct / 2 << endl;
}