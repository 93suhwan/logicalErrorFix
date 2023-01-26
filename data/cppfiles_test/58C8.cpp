#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 2e5;
const int mod = 998244353;
int x[maxn], y[maxn], fac[maxn << 1], fav[maxn << 1];
int t[maxn << 2], vis[maxn];
void pushup(int rt) { t[rt] = t[rt << 1] + t[rt << 1 | 1]; }
void build(int rt, int l, int r) {
  if (l == r) {
    t[rt]++;
    return;
  }
  int mid = l + r >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  pushup(rt);
}
void add(int rt, int l, int r, int x, int v) {
  if (l == r) {
    t[rt] += v;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid) add(rt << 1, l, mid, x, v);
  if (x >= mid + 1) add(rt << 1 | 1, mid + 1, r, x, v);
  pushup(rt);
}
int qry(int rt, int l, int r, int k) {
  if (l == r) return l;
  int mid = l + r >> 1;
  if (t[rt << 1] >= k) return qry(rt << 1, l, mid, k);
  return qry(rt << 1 | 1, mid + 1, r, k - t[rt << 1]);
}
int qpow(int a, int b, int c) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % c;
    b >>= 1;
    a = 1ll * a * a % c;
  }
  return ans;
}
int C(int a, int b) {
  if (a < b) return 0;
  return 1ll * fac[a] * fav[a - b] % mod * fav[b] % mod;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < (maxn << 1); ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  fav[(maxn << 1) - 1] = qpow(fac[(maxn << 1) - 1], mod - 2, mod);
  for (int i = (maxn << 1) - 2; i >= 0; --i)
    fav[i] = 1ll * fav[i + 1] * (i + 1) % mod;
  build(1, 1, maxm);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &x[i], &y[i]);
    }
    int cnt = 0;
    vector<int> now, vs;
    for (int i = m - 1; i >= 0; --i) {
      int u = qry(1, 1, maxm, y[i]);
      if (!vis[u]) cnt++;
      vis[u] = 1;
      vs.push_back(u);
      now.push_back(qry(1, 1, maxm, y[i] - 1));
      add(1, 1, maxm, now.back(), -1);
    }
    printf("%d\n", C(2 * n - 1 - cnt, n));
    for (auto u : now) add(1, 1, maxm, u, 1);
    for (auto u : vs) vis[u] = 0;
  }
}
