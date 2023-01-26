#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, f = 1;
  char _ch = getchar();
  while (!('0' <= _ch && _ch <= '9')) (_ch == '-') && (f = -1), _ch = getchar();
  while (('0' <= _ch && _ch <= '9')) s = s * 10 + _ch - 48, _ch = getchar();
  return s * f;
}
const int N = 2e5 + 10;
int n, m, s[N], vis[N], fa[N];
int u[N], v[N], h[N];
vector<pair<int, int> > G[N];
vector<int> T[N];
void dfs(int x, int pa) {
  for (int t : T[x])
    if (t != pa) fa[t] = x, dfs(t, x);
}
inline void work() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    fa[i] = vis[i] = s[i] = 0;
    G[i].clear();
    T[i].clear();
  }
  for (int i = 1, x, y, z, w; i < n; i++) {
    x = read(), y = read(), z = read();
    u[i] = x, v[i] = y, h[i] = z;
    T[x].push_back(y);
    T[y].push_back(x);
    if (x > y) swap(x, y);
    if (z != -1) {
      for (w = 0; z; z >>= 1) w ^= 1;
      G[x].push_back({y, w});
      G[y].push_back({x, w});
    }
  }
  for (int i = 1, a, b, p; i <= m; i++) {
    a = read(), b = read(), p = read();
    G[a].push_back({b, p});
    G[b].push_back({a, p});
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      q.push(i);
      while (!q.empty()) {
        int p = q.front();
        q.pop();
        vis[p] = 1;
        for (pair<int, int> e : G[p]) {
          int t = e.first, c = e.second;
          if (!vis[t])
            vis[t] = 1, s[t] = s[p] ^ c, q.push(t);
          else if (s[t] != s[p] ^ c) {
            cout << "NO\n";
            return;
          }
        }
      }
    }
  dfs(1, 0);
  cout << "YES\n";
  for (int i = 1; i <= n - 1; i++) {
    int x = u[i], y = v[i], z = h[i];
    if (z != -1)
      cout << x << ' ' << y << ' ' << z << '\n';
    else {
      cout << x << ' ' << y << ' ';
      cout << (s[x] ^ s[y]) << '\n';
    }
  }
}
signed main() {
  int t = read();
  while (t--) work();
  return 0;
}
