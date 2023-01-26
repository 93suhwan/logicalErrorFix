#include <bits/stdc++.h>
using namespace std;
const int N = 300200;
int n, m;
int h[N];
int a[N], b[N];
vector<int> g[N];
int used[N];
int par[N][21];
int timer;
int tin[N], tout[N];
inline int upper(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int lca(int u, int v) {
  if (upper(u, v)) return u;
  if (upper(v, u)) return v;
  for (int i = 20; i >= 0; --i) {
    if (!upper(par[v][i], u)) v = par[v][i];
  }
  return par[v][0];
}
vector<int> e[N];
int PAR[N];
inline void dfs(int v, int p = 0) {
  used[v] = 1;
  tin[v] = ++timer;
  par[v][0] = p;
  for (int i = 1; i <= 20; ++i) {
    par[v][i] = par[par[v][i - 1]][i - 1];
  }
  for (int to : g[v]) {
    if (!used[to]) {
      e[v].push_back(to);
      e[to].push_back(v);
      used[to] = 1;
      dfs(to, v);
    }
  }
  tout[v] = ++timer;
}
inline void calc(int v) {
  for (int to : g[v]) {
    if (par[to][0] == v) {
      calc(to);
      h[v] ^= h[to];
    }
  }
}
int ans = 0;
inline int solve(int v) {
  int s = 0;
  for (int to : g[v]) {
    if (par[to][0] == v) {
      s += solve(to);
    }
  }
  if (s % 2 == 0) {
    ans += s / 2;
    return h[v];
  } else {
    ans += s / 2;
    if (!h[v]) {
      ans++;
      return 0;
    } else
      return 1;
  }
}
inline void go(int v, int p = 0) {
  PAR[v] = p;
  for (int to : e[v]) {
    if (to != p) go(to, v);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> a[i] >> b[i];
    h[a[i]] ^= 1;
    h[b[i]] ^= 1;
  }
  calc(1);
  solve(1);
  vector<int> res;
  if (ans == 0) {
    cout << "YES\n";
    for (int i = 1; i <= q; ++i) {
      res.clear();
      go(a[i]);
      int x = b[i];
      while (x != a[i]) {
        res.push_back(x);
        x = PAR[x];
      }
      res.push_back(a[i]);
      cout << res.size() << '\n';
      reverse(res.begin(), res.end());
      for (int x : res) cout << x << ' ';
      cout << '\n';
    }
  } else {
    cout << "NO\n";
    cout << ans;
  }
  return 0;
}
