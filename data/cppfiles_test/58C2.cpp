#include <bits/stdc++.h>
using namespace std;
const int maxn = 200001;
const int mod = 998244353;
int n, m;
int sum[maxn << 2];
int y[maxn], x;
int vis[maxn];
int fac[maxn << 1], rfac[maxn << 1];
int mul(int a, int b) { return 1LL * a * b % mod; }
int qpow(int a, int q) {
  int res = 1;
  while (q) {
    if (q & 1) res = mul(res, a);
    q >>= 1;
    a = mul(a, a);
  }
  return res;
}
void init() {
  fac[0] = 1;
  int n = maxn * 2;
  for (int i = 1; i < n; ++i) {
    fac[i] = mul(fac[i - 1], i);
  }
  rfac[n - 1] = qpow(fac[n - 1], mod - 2);
  for (int i = n - 2; i >= 0; --i) {
    rfac[i] = mul(rfac[i + 1], i + 1);
  }
}
void pushup(int rt) { sum[rt] = sum[(rt << 1)] + sum[(rt << 1 | 1)]; }
void build(int rt, int l, int r) {
  if (l == r) {
    sum[rt] = 1;
    return;
  }
  int mid = (l + r) / 2;
  build((rt << 1), l, mid);
  build((rt << 1 | 1), mid + 1, r);
  pushup(rt);
}
int query(int rt, int l, int r, int val) {
  if (l == r) {
    return l;
  }
  int mid = (l + r) >> 1;
  if (val <= sum[(rt << 1)]) return query((rt << 1), l, mid, val);
  return query((rt << 1 | 1), mid + 1, r, val - sum[(rt << 1)]);
}
void update(int rt, int l, int r, int pos, int val) {
  if (l == r) {
    sum[rt] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update((rt << 1), l, mid, pos, val);
  else
    update((rt << 1 | 1), mid + 1, r, pos, val);
  pushup(rt);
}
int C(int a, int b) { return mul(mul(fac[a], rfac[b]), rfac[a - b]); }
int main() {
  int t;
  scanf("%d", &t);
  init();
  int len = maxn - 1;
  build(1, 1, len);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &x, &y[i]);
    }
    memset(vis, 0, sizeof(vis));
    int c = 0;
    vector<int> ve;
    for (int i = m - 1; i >= 0; --i) {
      int p = query(1, 1, len, y[i]);
      int q = query(1, 1, len, y[i] + 1);
      update(1, 1, len, p, 0);
      if (!vis[q]) {
        vis[q] = 1;
        ++c;
      }
      ve.push_back(p);
    }
    printf("%d\n", C(2 * n - c - 1, n));
    for (auto u : ve) {
      update(1, 1, len, u, 1);
    }
  }
}
