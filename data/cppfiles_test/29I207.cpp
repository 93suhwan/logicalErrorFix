#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mii map<int, int>
#define mll map<ll, ll>
#define adfor(i, lst) for (auto &i : lst)
#define forEach(i, ar) for (auto i : ar)
#define ifor(i, a, b) for (ll i = a; i < b; i++)
#define ifor1(i, a, b) for (ll i = a; i <= b; i++)
#define dfor(i, a, b) for (ll i = a; i >= b; --i)
#define dfor1(i, a, b) for (ll i = a; i > b; --i)
#define all(v) v.begin(), v.end()
#define maxi INT_MAX
#define mini INT_MIN

const int mod = 1e9 + 7, inf = 998244353, N = 2e5 + 7;

ll gcd(vll &a, ll n)
{
    ll ans = a[0];
    ifor(i, 1, n)
    {
        ans = __gcd(ans, a[i]);
    }
    return ans;
}

int testCases()
{
    int t = 1;
    cin >> t;
    return t;
}

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    adfor(i, a)
    {
        cin >> i;
    }
    ll ct1 = count(all(a), 1ll);
    ll ct0 = count(all(a), 0ll);
    ll ans = 0;
    ans = (ct0 * (ct0 + 1) / 2) + (ct1 * (ct1 + 1) / 2);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = testCases();
    while (t--)
    {
        solve();
#ifndef ONLINE_JUDGE
        cout
            << "------------------------- " << endl;
#endif
    }

    return 0;
}
