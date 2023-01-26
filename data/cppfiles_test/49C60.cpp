#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int f[N], g[N], l[N], lb[N], n;
void push(int o) {
  int u = g[o], v = l[lb[o] + 1] - 1;
  swap(g[f[u]], g[f[v]]);
  swap(f[u], f[v]);
}
void del(int o) {
  int u = g[o], v = l[lb[o]];
  swap(g[f[u]], g[f[v]]);
  swap(f[u], f[v]);
}
struct node {
  int x, y, z;
};
vector<int> p[N];
vector<node> q[N];
int ans[N], a[N];
void dfs(int u) {
  int blog = lb[a[u]];
  push(a[u]);
  l[blog + 1]--;
  lb[a[u]]++;
  for (auto [a, b, c] : q[u]) {
    if (l[a] + b - 1 <= n) {
      ans[c] = f[l[a] + b - 1];
    } else
      ans[c] = -1;
  }
  for (auto v : p[u]) dfs(v);
  del(a[u]);
  l[lb[a[u]]]++;
  lb[a[u]]--;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int m, fa;
    cin >> n >> m;
    l[0] = 1;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      l[i] = n + 1;
      lb[i] = 0;
      f[i] = i;
      g[i] = i;
      p[i].clear();
      q[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
      cin >> fa;
      p[fa].push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
      int v, l, k;
      cin >> v >> l >> k;
      q[v].push_back({l, k, i});
    }
    dfs(1);
    for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
    cout << '\n';
  }
}
