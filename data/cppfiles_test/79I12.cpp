#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
typedef long double ld;
typedef ll int lli;
typedef pair<int, int> p32;
typedef pair<lli, lli> p64;
typedef pair<double, double> pdd;
typedef vector<lli> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef vector<vp64> vvp64;
typedef vector<bool> vb;
typedef queue<lli> q64;
typedef priority_queue<int, vector<int>, greater<int>> min_heap32;
typedef priority_queue<lli, vector<lli>, greater<lli>> min_heap64;
typedef priority_queue<int> max_heap32;
typedef priority_queue<lli> max_heap64;
typedef unordered_map<int, int> umap32;
typedef unordered_map<lli, lli> umap64;
typedef tree<p64, null_type, less<p64>, rb_tree_tag, tree_order_statistics_node_update> ordered_setP64;
typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> ordered_set64;
typedef tree<lli, null_type, greater<lli>, rb_tree_tag, tree_order_statistics_node_update> ordered_setR64;
typedef tree<lli, null_type, less_equal<lli>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset64;
typedef tree<lli, null_type, greater_equal<lli>, rb_tree_tag, tree_order_statistics_node_update> ordered_multisetR64;
lli MOD = 1000000007;
double eps = 1e-9;
ld PI = ((ld)22 / (ld)7);
#define print(v, i) for (auto i = 0; i < v.size(); i++)
#define forn(i, e) for (auto i = 0; i < e; i++)
#define forsn(i, s, e) for (auto i = s; i < e; i++)
#define rforn(i, s) for (auto i = s; i >= 0; i--)
#define rforsn(i, s, e) for (auto i = s; i >= e; i--)
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define pob pop_back
#define eb emplace_back
#define F first
#define S second
#define INF 1000000000000000000
#define elif else if
#define fbo find_by_order
#define fast_cin                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((lli)(x).size())
#define sq(a) (a) * (a)
#define nod(x) floor(log10(x) + 1) // here base of no. is 10 but in reality we can have base of any number
// works well till 19 digits
#define feq(a, b) (abs(a - b) < 1e-9) ? true : false // use in if else condition only
vb vis;
v64 dp;
v64 a;
v64 b;
vp64 ext;
lli N;
v64 ans;


void dfs(lli n)
    {
        if(dp[n] == 1)
            {
                ans.pb(0);
                return;
            }
        lli m = INF;
            for (lli i = 1; i <= a[n]; i++)
            {
                lli var = n - i + b[n - i];
                if (var == n)
                    continue;
                // cout << var << " "<<n << nl;
                m = min(dp[var], m);
            }
            for (lli i = 1; i <= a[n]; i++)
            {
                lli var = n - i + b[n - i];
                if (var == n)
                    continue;
                // cout << var << " "<<n << nl;
                if(m == dp[var]) 
                    {
                        ans.pb(n-i);
                        dfs(var);
                    }
            }
    }
lli knapsack(lli n)
{
    // cout << n << nl;
    if (dp[n] != -1)
        return dp[n];
    else
    {
        if (!vis[n])
        {
            vis[n] = true;
            if (n - a[n] == 0)
            {
                // cout << n << nl;
                ext[n] = {0,0};
                return dp[n] = 1;
            }
            lli m = INF;
            for (lli i = 1; i <= a[n]; i++)
            {
                lli var = n - i + b[n - i];
                if (var == n)
                    continue;
                // cout << var << " "<<n << nl;
                m = min(knapsack(var), m);
            }
            // cout << m <<" *"<<  nl;
            if (m == INF)
            {
                return dp[n] = INF;
            }
            else
            {
                for (lli i = 1; i <= a[n]; i++)
                {
                    lli var = n - i + b[n-i];
                    if (var == n)
                        continue;
                    if (dp[var] == m)
                    {
                        // if(n == 3) cout << var <<" "<< i << b[n]  << nl;
                        ext[n] = {n-i,var};
                    }
                }
            // if(m == INF) return dp[n] = INF;
            return dp[n] = 1 + m;
            }
        }
        else
        {
            return dp[n] = INF;
        }
    }
}

void solve()
{
    cin >> N;
    a.assign(N + 1, 0);
    b.assign(N + 1, 0);
    vis.assign(N + 1, false);
    dp.assign(N + 1, -1);
    ext.assign(N + 1, {-1,-1});
    for (lli i = 1; i <= N; i++)
        cin >> a[i];
    for (lli i = 1; i <= N; i++)
        cin >> b[i];
    knapsack(N);
    // for(lli i=1;i<=N;i++)
    // cout << dp[i] <<" ";
    // cout << nl;
    // for(lli i=1;i<=N;i++)
    // cout << ext[i].F <<" " << ext[i].S << nl;
    // // cout << nl;
    if (dp[N] == INF)
    {
        cout << "-1" << nl;
    }
    else
    {
        // lli j = 0;
        // for (lli i = N; i!= 0; i = ext[i].S )
        // {
        //     // j++;
        //     ans.pb(ext[i].F);
        //     // if(j == 2 || i == 0) break;
        // }

        // ans.pb(0);
        dfs(N);
        cout << sz(ans) << nl;
        for (lli i = 0; i < sz(ans); i++)
            cout << ans[i] << " ";
        cout << nl;
    }
}
signed main()
{
    fast_cin;
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\HP\\c++ programs\\STL_imp_concepts\\input.txt", "r", stdin);
    freopen("C:\\Users\\HP\\c++ programs\\STL_imp_concepts\\output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    for (lli i = 1; i <= t; i++)
        solve();
}