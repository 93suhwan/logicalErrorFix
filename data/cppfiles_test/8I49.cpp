#include <bits/stdc++.h>
using namespace std;
const int dir[5] = {0, -1, 0, 1, 0};
const int maxn = 100010;
const int oo = 1e9;
const int mod = 1000000007;
int n, q, timeDFS, lg2, table[maxn][20], h[maxn];
long long a[maxn], dis[maxn], f[maxn];
pair<int, int> euler[maxn];
vector<int> graph[maxn];
void EUL(int u, int p, int d) {
  euler[u].first = ++timeDFS;
  dis[timeDFS] = d;
  for (int j = 1; j <= lg2; ++j) table[u][j] = table[table[u][j - 1]][j - 1];
  for (int v : graph[u])
    if (v != p) {
      table[v][0] = u;
      h[v] = h[u] + 1;
      EUL(v, u, d + a[v]);
    }
  euler[u].second = timeDFS;
}
void update(int p, long long k) {
  for (; p <= n; p += p & -p) f[p] += k;
}
long long get(int p) {
  long long res = 0;
  for (; p; p -= p & -p) res += f[p];
  return res;
}
int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int j = lg2; j >= 0; --j)
    if (h[table[u][j]] >= h[v]) u = table[u][j];
  if (u == v) return u;
  for (int j = lg2; j >= 0; --j)
    if (table[u][j] != table[v][j]) {
      u = table[u][j];
      v = table[v][j];
    }
  return table[u][0];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  long long u, v;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  lg2 = log2(n);
  table[1][0] = 1;
  EUL(1, -1, a[1]);
  for (int i = 1; i <= n; ++i) {
    update(i, dis[i]);
    update(i + 1, -dis[i]);
  }
  int t;
  while (q--) {
    cin >> t >> u >> v;
    if (t == 1) {
      v = abs(v);
      update(euler[u].first, v - a[u]);
      update(euler[u].second + 1, a[u] - v);
      a[u] = v;
    } else {
      int anc = lca(u, v);
      long long du = get(euler[u].first);
      long long dv = get(euler[v].first);
      long long da = get(euler[anc].first);
      cout << du * 2 + dv * 2 - da * 4 - a[u] - a[v] + a[anc] * 2 << '\n';
    }
  }
}
