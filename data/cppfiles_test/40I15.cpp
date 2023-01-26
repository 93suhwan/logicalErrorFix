#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAXN = 3e5 + 5;
vector<int> edges[MAXN];
int deg[MAXN];
int fa[MAXN][20], dep[MAXN];
bool vis[MAXN];
void dfs(int cur, int fath = 0)
{
    if (vis[cur])
        return;
    vis[cur] = true;
    dep[cur] = dep[fath] + 1;
    fa[cur][0] = fath;
    for (int i = 1; i <= __lg(dep[cur]); ++i)
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    for (auto to : edges[cur])
        dfs(to, cur);
}
int lca(int a, int b)
{
    if (dep[a] > dep[b])
        swap(a, b);
    while (dep[a] != dep[b])
        b = fa[b][__lg(dep[b] - dep[a])];
    if (a == b)
        return a;
    for (int k = __lg(dep[a]); k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return fa[a][0];
}
void print_path(int u, int v)
{
    int a = lca(u, v);
    list<int> A, B;
    while (u != a)
        A.push_back(u), u = fa[u][0];
    while (v != a)
        B.push_front(v), v = fa[v][0];
    for (auto e : A)
        cout << e << ' ';
    cout << a << ' ';
    for (auto e : B)
        cout << e << ' ';
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    int q;
    cin >> q;
    vector<pair<int, int>> V;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        V.emplace_back(u, v);
        deg[u]++, deg[v]++;
    }
    int cnt = count_if(deg + 1, deg + n + 1, [](int x)
                       { return x & 1; });
    if (cnt)
        cout << "NO" << endl
             << cnt / 2 << endl;
    else
    {
        cout << "YES" << endl;
        for (auto [u, v] : V)
            print_path(u, v);
    }
    return 0;
}
