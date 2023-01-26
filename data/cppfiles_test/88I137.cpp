#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
///#include "testlib.h"
using namespace std;
using namespace __gnu_pbds;
template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define int128 __int128
#define float128 __float128
#define fbo find_by_order
#define ook order_of_key
///clock() / (double) CLOCKS_PER_SEC >= 1.96
#define sz size
#define en "\n"
bool us[1000000];
int ps[1000000];
int a[1000000];
ll t[330][3000];
void build(int l, int r, int v, int izm)
{
    if (l == r)
        t[v][izm] = 0;
    else
    {
        build(l, (l+r) / 2, v*2+1, izm);
        build((l+r) / 2+1, r, v*2+2, izm);
        t[v][izm] = 0;
    }
}
void add(int l, int r, int p, int v, int izm)
{
    if (l > p || r < p)
        return;
    if (l == r)
    {
        t[v][izm]++;
        return;
    }
    add(l, (l+r) / 2, p, v*2+1, izm);
    add((l+r) / 2+1, r, p, v*2+2, izm);
    t[v][izm] = t[v*2+1][izm]+t[v*2+2][izm];
    return;
}
ll get(int l, int r, int lx, int rx, int v, int izm)
{
    if (l > rx || r < lx)
        return 0;
    if (l >= lx && r <= rx)
        return t[v][izm];
    return get(l, (l+r) / 2, lx, rx, v*2+1, izm)+get((l+r) / 2+1, r, lx, rx, v*2+2, izm);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > x;
    for (int i = 0; i < n*m; i++)
    {
        cin >> a[i];
        x.pb(mp(a[i], i));
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < n*m; i++)
        cout << x[i].fir << ' ' << x[i].sec << en;
    int p = 0, lx = 0;
    for (int i = 0; i < n*m; i++)
        if (i >= p)
        {
            for (int j = i; j < n*m; j++)
                if (x[i].fir != x[j].fir)
                    break;
                else
                    p = j+1;
            int lft = i;
            while (lft <= p-1)
            {
                int r = p-1;
                if ((p-1) / m > lft / m)
                    r = ((lft+m) / m)*m-1;
                for (int j = r; j >= lft; j--)
                {
                    ps[x[j].sec] = lx;
                    lx++;
                }
                lft = r+1;
            }
            ///ps[x[j].sec] = j;
        }
    for (int i = 0; i < n; i++)
        build(0, m-1, 0, i);
    ll res = 0;
    for (int i = 0; i < n*m; i++)
    {
        int p1 = ps[i] / m, p2 = ps[i] % m;
        res += get(0, m-1, 0, p2, 0, p1);
        add(0, m-1, p2, 0, p1);
    }
    cout << res << en;
}
int main()
{
    //freopen("birch.in", "r", stdin);
    //freopen("birch.out", "w", stdout);
    ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--)
        solve();
}

