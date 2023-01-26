#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

long long MOD = 1000000007;
const int MAXN = 100001;
const int l = 20;
long long t[4 * MAXN];
vector<long long> dfsdists;
vector<pair<int, int>> stree;
vector<long long> a;
vector<set<int>> adj;
vector<vector<int>> up;
vector<long long> dbg(MAXN);

void dfs(int i, int p, long long d)
{
    if (p)
    {
        d += a[p];
        d += a[i];
        up[i][0] = p;
    }
    stree[i].first = dfsdists.size();
    dfsdists.push_back(d);
    for (int lvl = 1; lvl <= l; ++lvl)
    {
        up[i][lvl] = up[up[i][lvl - 1]][lvl - 1];
    }
    for (auto x : adj[i])
    {
        if (x != p)
        {
            dfs(x, i, d);
        }
    }
    stree[i].second = dfsdists.size() - 1;
}

bool is_ancestor(int u, int v)
{
    return stree[u].first <= stree[v].first && stree[u].second >= stree[v].second;
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = dfsdists[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, long long add)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        t[v] += add;
    }
    else
    {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

int getval(int v, int tl, int tr, int pos)
{
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + getval(v * 2, tl, tm, pos);
    else
        return t[v] + getval(v * 2 + 1, tm + 1, tr, pos);
}

void debug(int n)
{
    for (int i = 1; i <= n; i++)
    {
        dbg[i] = getval(1, 0, n - 1, stree[i].first);
    }
}

void Solve()
{
    long long n, q, x;
    int u, v;
    cin >> n >> q;
    stree = vector<pair<int, int>>(n + 1);
    up.assign(n + 1, vector<int>(l + 1, 1));
    a = vector<long long>(n + 1);
    a[0] = 0;
    adj = vector<set<int>>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = abs(x);
    }
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    dfs(1, 0, 0);
    build(1, 0, n - 1);
    debug(n);
    for (int i = 0; i < q; i++)
    {
        cin >> u >> v >> x;
        if (u == 1)
        {
            x = abs(x);
            x -= a[v];
            if (v != 1)
            {
                update(1, 0, n - 1, stree[v].first, stree[v].second, x);
            }
            debug(n);
            update(1, 0, n - 1, stree[v].first + 1, stree[v].second, x);
            debug(n);
        }
        else
        {
            u = lca(v, x);
            debug(n);
            long long ans = getval(1, 0, n - 1, stree[v].first) + getval(1, 0, n - 1, stree[x].first) - 2 * getval(1, 0, n - 1, stree[u].first);
            debug(n);
            cout << ans << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ntest = 1;
    for (long long i = 0; i < ntest; i++)
    {
        Solve();
    }
}