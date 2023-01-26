#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6e5 + 5;
const int MOD = 998244353;
long long q_pow(long long a, long long b, long long p = MOD) {
  long long ret = 1;
  for (; b; a = a * a % p, b >>= 1)
    if (b & 1) ret = ret * a % p;
  return ret;
}
long long q_inv(long long x, long long p = MOD) { return q_pow(x, p - 2, p); }
int fac[MAXN], ifac[MAXN];
void build(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
  ifac[n] = q_inv(fac[n]);
  for (int i = n - 1; i >= 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}
int binom(int n, int m) {
  return 1ull * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}
int T, N, M, D;
set<int> S;
int rt, ls[MAXN], rs[MAXN], val[MAXN], key[MAXN], siz[MAXN], Tlen, tag[MAXN];
int newnode(int v) {
  int p = ++Tlen;
  val[p] = v, key[p] = rand(), siz[p] = 1, ls[p] = rs[p] = 0, tag[p] = 0;
  return p;
}
void pushup(int x) { siz[x] = siz[ls[x]] + siz[rs[x]] + 1; }
void cov(int o, int k) {
  if (o) val[o] += k, tag[o] += k;
}
void pushdown(int o) {
  if (tag[o]) cov(ls[o], tag[o]), cov(rs[o], tag[o]), tag[o] = 0;
}
void split(int now, int k, int& x, int& y) {
  if (!now) {
    x = y = 0;
    return;
  }
  pushdown(now);
  if (val[now] <= k)
    x = now, split(rs[now], k, rs[now], y);
  else
    y = now, split(ls[now], k, x, ls[now]);
  pushup(now);
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  pushdown(x), pushdown(y);
  if (key[x] > key[y]) {
    rs[x] = merge(rs[x], y), pushup(x);
    return x;
  } else {
    ls[y] = merge(x, ls[y]), pushup(y);
    return y;
  }
}
int main() {
  build(400000);
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &M);
    int x, y, r1, r2, r3, r4, cnt = 0;
    Tlen = 0;
    rt = 0;
    for (int i = 1; i <= M; ++i) {
      scanf("%d%d", &x, &y);
      split(rt, y - 1, r1, r2);
      split(r2, y, r3, r4);
      if (r3)
        r2 = merge(r3, r4), cov(r2, 1), rt = merge(r1, r2);
      else
        r2 = merge(newnode(y), r4), cov(r2, 1), rt = merge(r1, r2), ++cnt;
    }
    printf("%d\n", binom(N - cnt + N - 1, N));
  }
  return 0;
}
