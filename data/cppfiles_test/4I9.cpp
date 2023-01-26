#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
const int N = 2e5 + 10;
int n, k, a[N];
vector<pair<int, int> > g[N];
inline void A(int &x, int y) { x = (x + y >= p ? x + y - p : x + y); }
inline void U(int &x, int y) { x = (x > y ? x : y); }
int del[N], si[N];
int mnsi, mnid;
inline void GetSi(int x, int fa) {
  si[x] = 1;
  for (auto e : g[x])
    if (e.second != fa && !del[e.second]) {
      GetSi(e.second, x);
      si[x] += si[e.second];
    }
}
inline void GetMx(int x, int fa, int al) {
  int mx = al - si[x];
  for (auto e : g[x])
    if (e.second != fa && !del[e.second]) {
      mx = max(mx, si[e.second]);
      GetMx(e.second, x, al);
    }
  if (mx < mnsi) mnsi = mx, mnid = x;
}
int f1[N], g1[N], f2[N], g2[N], sw1, sw2;
int ans;
void PushIn(int x, int fa, int fe, int sm, int sw, int *f, int *G, int &mxsw) {
  if (sw > k) return;
  if (sw > mxsw) f[sw] = f[mxsw], G[sw] = G[mxsw], mxsw = sw;
  A(sm, a[x]);
  A(f[sw], sm);
  A(G[sw], 1);
  for (auto e : g[x]) {
    int y = e.second, z = e.first;
    if (del[y] || y == fa) continue;
    PushIn(y, x, z, sm, sw + (fe != z), f, G, mxsw);
  }
}
inline int Get(int *f, int sz, int y) { return f[y <= sz ? y : sz]; }
void Calc(int x, int fa, int fe, int sm, int sw) {
  if (sw > k) return;
  A(sm, a[x]);
  if (sw < k)
    ans = (ans +
           1ll * sm * (Get(g1, sw1, k - sw - 1) - Get(g2, sw2, k - sw - 1)) +
           (Get(f1, sw1, k - sw - 1) - Get(f2, sw2, k - sw - 1))) %
          p;
  ans = (ans + 1ll * sm * Get(g2, sw2, k - sw) + Get(f2, sw2, k - sw)) % p;
  for (auto e : g[x]) {
    int y = e.second, z = e.first;
    if (del[y] || y == fa) continue;
    Calc(y, x, z, sm, sw + (fe != z));
  }
}
inline void Solve(int x) {
  GetSi(x, 0);
  mnsi = 1e9;
  GetMx(x, 0, si[x]);
  int u = mnid;
  sw1 = 0, sw2 = 0;
  A(f1[0], a[u]);
  A(f2[0], a[u]);
  g1[0] = g2[0] = 1;
  ans += a[u];
  int la = -1;
  for (auto e : g[u]) {
    int y = e.second, z = e.first;
    if (z != la) {
      for (int i = 0; i <= sw2; ++i) f2[i] = g2[i] = 0;
      sw2 = 0;
      la = z;
      A(f2[0], a[u]);
      A(g2[0], 1);
    }
    if (del[y]) continue;
    Calc(y, u, z, 0, 0);
    PushIn(y, u, z, a[u], 0, f1, g1, sw1);
    PushIn(y, u, z, a[u], 0, f2, g2, sw2);
  }
  for (int i = 0; i <= sw1; ++i) f1[i] = g1[i] = 0;
  for (int i = 0; i <= sw2; ++i) f2[i] = g2[i] = 0;
  del[u] = 1;
  for (auto e : g[u])
    if (!del[e.second]) Solve(e.second);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1, x, y, z; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    g[x].push_back(pair<int, int>(z, y));
    g[y].push_back(pair<int, int>(z, x));
  }
  for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
  Solve(1);
  if (ans < 0) ans += p;
  printf("%d\n", ans);
  return 0;
}
