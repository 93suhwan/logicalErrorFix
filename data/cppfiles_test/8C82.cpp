#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e5 + 10;
int n, m;
vector<int> e[Nmax];
int par[Nmax][20];
int in[Nmax], out[Nmax], ti;
void dfs(int u, int p) {
  in[u] = ++ti;
  par[u][0] = p;
  for (int i = 1; i < 20; ++i) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v : e[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  out[u] = ti;
}
long long BIT[Nmax];
void add(int id, int delta) {
  for (; id <= n; id += id & (-id)) BIT[id] += delta;
}
long long get(int id) {
  long long ans = 0;
  for (; id; id -= id & (-id)) ans += BIT[id];
  return ans;
}
int check(int u, int v) { return in[u] <= in[v] && out[v] <= out[u]; }
int LCA(int u, int v) {
  if (check(u, v)) return u;
  for (int i = 19; i >= 0; --i)
    if (par[u][i] && !check(par[u][i], v)) u = par[u][i];
  return par[u][0];
}
int a[Nmax];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) add(in[i], a[i]), add(out[i] + 1, -a[i]);
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, c;
      cin >> u >> c;
      c = abs(c);
      add(in[u], c - a[u]);
      add(out[u] + 1, a[u] - c);
      a[u] = c;
    } else {
      int u, v;
      cin >> u >> v;
      int w = LCA(u, v);
      cout << (get(in[u]) + get(in[v]) - 2 * get(in[w]) + a[w]) * 2 - a[u] -
                  a[v]
           << '\n';
    }
  }
}
