#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ci(a) \
    ll a;     \
    cin >> a;
ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}
bool prime(ll a)
{
    if (a <= 11)
        return 0;
    if (a < 4)
        return 1;
    if (a % 2 == 0)
        return 0;
    for (ll i = 3; i * i <= a; i += 2)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ci(n);
        ll a[n];
        ll ans = 1, flag = 1;
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i > 0)
            {
                if (a[i - 1] == a[i] && a[i] != 0)
                {
                    ans += 5;
                }
                else if (a[i - 1] != a[i])
                {
                    ans += 1;
                }
                else if (a[i - 1] == a[i] && a[i] == 0)
                {
                    flag = 0;
                }
            }
        }
        if (flag)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}