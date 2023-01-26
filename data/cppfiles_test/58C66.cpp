#include <bits/stdc++.h>
const int N = 2e5 + 5, MOD = 998244353;
int n, m, x[N], y[N], roll[N], val[N << 2], fac[N << 1], ifac[N << 1];
std::set<int> pos;
int qpow(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) res = (long long)res * a % MOD;
    a = (long long)a * a % MOD;
    p >>= 1;
  }
  return res;
}
void init(int l, int r, int rt) {
  val[rt] = r - l + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  init(l, mid, rt << 1);
  init(mid + 1, r, rt << 1 | 1);
}
int query(int l, int r, int rt, int k) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (val[rt << 1] >= k)
    return query(l, mid, rt << 1, k);
  else
    return query(mid + 1, r, rt << 1 | 1, k - val[rt << 1]);
}
void modify(int l, int r, int rt, int p, int v) {
  val[rt] += v;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (p <= mid)
    modify(l, mid, rt << 1, p, v);
  else
    modify(mid + 1, r, rt << 1 | 1, p, v);
}
int C(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return (long long)fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < N * 2; i++) fac[i] = (long long)fac[i - 1] * i % MOD;
  ifac[N * 2 - 1] = qpow(fac[N * 2 - 1], MOD - 2);
  for (int i = N * 2 - 1; i; i--) ifac[i - 1] = (long long)ifac[i] * i % MOD;
  int test;
  scanf("%d", &test);
  init(1, N - 1, 1);
  while (test--) {
    scanf("%d %d", &n, &m);
    pos.clear();
    for (int i = 1; i <= m; i++) scanf("%d %d", &x[i], &y[i]);
    for (int i = m; i; i--) {
      int p = query(1, N - 1, 1, y[i]), q = query(1, N - 1, 1, y[i] + 1);
      modify(1, N - 1, 1, p, -1);
      roll[i] = p;
      pos.insert(q);
    }
    for (int i = 1; i <= m; i++) modify(1, N - 1, 1, roll[i], 1);
    int c = (int)pos.size();
    printf("%d\n", C(n * 2 - 1 - c, n));
  }
  return 0;
}
