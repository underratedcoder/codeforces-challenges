#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<char> vc;
typedef set<char> sc;
typedef pair<int, int> pii;
typedef multiset<int> msi;
typedef multiset<char> msc;
#define forp(i, a, b) for (ll i = a; i < b; i++)
#define form(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll temp = power(x, y / 2);
    if (y % 2)
        return temp * temp * x;

    else
        return temp * temp;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "! " << 1 << endl;
    }

    else
    {
        ll low = 0, high = n;
        ll mid = low + high + 1;
        mid /= 2;
        ll ans;

        while (1)
        {
            cout << "? " << mid << endl;
            cout.flush();
            ll x1, x2, x3;
            cin >> x2;

            if (mid == 1)
            {
                x1 = x2 + 1;
                cout << "? " << mid + 1 << endl;
                cout.flush();
                cin >> x3;
            }

            else if (mid == n)
            {
                x3 = x2 + 1;
                cout << "? " << mid - 1 << endl;
                cout.flush();
                cin >> x1;
            }

            else
            {
                cout << "? " << mid - 1 << endl;
                cout.flush();
                cin >> x1;
                cout << "? " << mid + 1 << endl;
                cout.flush();
                cin >> x3;
            }

            // cout<<x1<<" "<<x2<<" "<<x3<<endl;
            if (x2 < x3 && x2 < x1)
            {
                ans = mid;
                break;
            }
            else if (x2 > x3 && x2 > x1)
            {
                low = mid;
            }
            else if (x2 > x3 && x2 < x1)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
            mid = low + high + 1;
            mid /= 2;
        }

        cout << "! " << ans << endl;
    }

    return 0;
}
