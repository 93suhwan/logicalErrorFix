#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    t = 1;
    cin >> t;
    while (t--)
    {
        ll n, m, i, j, k;
        cin >> n;
        vector<ll> a(n);
        for (i = 0; i < n; i++)
            cin >> a[i];
        ll o = a[0], e = a[1];
        for (i = 0; i < n; i += 2)
            o = __gcd(o, a[i]);
        for (i = 1; i < n; i += 2)
            e = __gcd(e, a[i]);
        bool f = 0;
        if (o != 1)
        {
            for (i = 1; i < n; i += 2)
            {
                if (a[i] % o == 0)
                {
                    f = 1;
                    break;
                }
            }
        }
        else if (e != 1)
        {
            for (i = 0; i < n; i += 2)
            {
                if (a[i] % e == 0)
                {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 1)
            cout << "0\n";
        else
        {
            if (o == 1)
                cout << e << "\n";
            else if (e == 1)
                cout << o << "\n";
            else if (o == 1 and e == 1)
                cout << "0\n";
            else
                cout << o << "\n";
        }
    }
    return 0;
}