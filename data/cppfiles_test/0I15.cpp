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
int f1[N], f2[N], sw1, sw2;
int ans;
void PushIn(int x, int fa, int fe, int sm, int sw, int *f, int &mxsw) {
  if (sw > k) return;
  if (sw > mxsw) f[sw] = f[mxsw], mxsw = sw;
  A(sm, a[x]);
  A(f[sw], sm);
  for (auto e : g[x]) {
    int y = e.second, z = e.first;
    if (del[y] || y == fa) continue;
    PushIn(y, x, z, sm, sw + (fe != z), f, mxsw);
  }
}
inline int Get(int *f, int sz, int y) { return f[y <= sz ? y : sz]; }
void Calc(int x, int fa, int fe, int sm, int sw) {
  if (sw > k) return;
  if (sw < k)
    ans = (ans +
           1ll * sm * (Get(f1, sw1, k - sw - 1) - Get(f2, sw2, k - sw - 1))) %
          p;
  A(sm, a[x]);
  ans = (ans + 1ll * sm * Get(f2, sw2, k - sw)) % p;
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
  printf("Solve %d\n", u);
  sw1 = 0, sw2 = 0;
  A(f1[0], a[u]);
  A(f2[0], a[u]);
  ++ans;
  int la = -1;
  for (auto e : g[u]) {
    int y = e.second, z = e.first;
    if (z != la) {
      for (int i = 0; i <= sw2; ++i) f2[i] = 0;
      sw2 = 0;
      la = z;
      A(f2[0], a[u]);
    }
    if (del[y]) continue;
    Calc(y, x, z, 0, 0);
    PushIn(y, x, z, a[u], 0, f1, sw1);
    PushIn(y, x, z, a[u], 0, f2, sw2);
  }
  printf("ans = %d\n", ans);
  for (int i = 0; i <= sw1; ++i) f1[i] = 0;
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
