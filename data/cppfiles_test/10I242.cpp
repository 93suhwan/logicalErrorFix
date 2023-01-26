#include <bits/stdc++.h>
#define ll long long
#define dl long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
using namespace std;
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll nCr(ll n, ll r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}
ll power(ll n, ll p, ll m)
{
    n %= m;
    long long res = 1;
    while (p > 0)
    {
        if (p & 1)
            res = res * n % m;
        n = n * n % m;
        p >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]].pb(i);
        }
        vector<int> ans(n, 0);
        int a = 0;
        for (auto i : m)
        {
            if (i.second.size() >= k)
                a += k;
            else
                a += i.second.size();
        }
        if (a % k == 0)
        {
            for (auto i : m)
            {
                for (int j = 0; j < min((int)i.second.size(), k); j++)
                    ans[i.second[j]] = j + 1;
            }
        }
        else
        {
            for (auto i : m)
            {
                for (int j = 0; j < min((int)i.second.size(), k); j++)
                {
                    if (a == 0)
                        break;
                    ans[i.second[j]] = j + 1;
                    a--;
                }
                if (a == 0)
                    break;
            }
        }
        for (int i : ans)
            cout << i << " ";
        cout << endl;
    }
}