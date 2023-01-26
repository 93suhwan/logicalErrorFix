#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 998244353;
int ls[100 * N], rs[100 * N], sum[100 * N], num[100 * N];
vector<int> cmp[N];
int b[N], opx[N], opy[N];
int frac[N], ifrac[N];
int n, m, T, cnt;
int ksm(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
void clear(int x, long long l, long long r) {
  sum[x] = num[x] = 0;
  long long mid = l + r >> 1;
  if (l == r) return;
  if (sum[ls[x]] && ls[x]) clear(ls[x], l, mid);
  if (sum[rs[x]] && rs[x]) clear(rs[x], mid + 1, r);
}
void update(int x, long long l, long long r, long long p, int delta,
            int number) {
  if (l == r) {
    sum[x] += delta;
    num[x] = number;
    return;
  }
  long long mid = l + r >> 1;
  if (p <= mid)
    update(ls[x] ? ls[x] : ls[x] = ++cnt, l, mid, p, delta, number);
  else
    update(rs[x] ? rs[x] : rs[x] = ++cnt, mid + 1, r, p, delta, number);
  sum[x] = sum[ls[x]] + sum[rs[x]];
}
pair<long long, int> query(int x, long long l, long long r, int rk) {
  if (l == r) return make_pair(l, num[x]);
  long long mid = l + r >> 1;
  if (rk <= sum[ls[x]]) return query(ls[x], l, mid, rk);
  return query(rs[x], mid + 1, r, rk - sum[ls[x]]);
}
void work() {
  scanf("%d%d", &n, &m);
  cnt = 1;
  clear(1, 1ll, 1ll * n * n);
  for (int i = 1; i <= n; ++i) {
    cmp[i].clear();
    update(1, 1ll, 1ll * n * n, 1ll * (i - 1) * n + 1ll, 1, i);
  }
  for (int i = 1; i <= m; ++i) scanf("%d%d", &opx[i], &opy[i]);
  for (int i = m; i >= 1; --i) {
    pair<long long, int> idx = query(1, 1ll, 1ll * n * n, opx[i]);
    pair<long long, int> idy = query(1, 1ll, 1ll * n * n, opy[i]);
    update(1, 1ll, 1ll * n * n, idy.first, -1, 0);
    update(1, 1ll, 1ll * n * n, idx.first + 1, 1, idy.second);
    idx = query(1, 1ll, 1ll * n * n, opy[i]);
    cmp[idy.second].push_back(idx.second);
  }
  b[1] = 1;
  for (int i = 1; i <= n; ++i) {
    b[i] = max(b[i], b[i - 1]);
    for (int j = 0; j < cmp[i].size(); ++j)
      b[cmp[i][j]] = max(b[cmp[i][j]], b[i] + 1);
  }
  if (b[n] == n) {
    puts("1");
    return;
  }
  printf("%lld\n",
         1ll * frac[2 * n - b[n]] * ifrac[n - b[n]] % mod * ifrac[n] % mod);
}
int main() {
  frac[0] = 1;
  for (int i = 1; i <= 2e5; ++i) frac[i] = 1ll * frac[i - 1] * i % mod;
  ifrac[200000] = ksm(frac[200000], mod - 2);
  for (int i = 199999; i >= 0; --i)
    ifrac[i] = 1ll * ifrac[i + 1] * (i + 1) % mod;
  scanf("%d", &T);
  while (T--) work();
}
