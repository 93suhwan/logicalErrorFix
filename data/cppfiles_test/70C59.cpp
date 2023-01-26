#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 1e3 + 7, P = 1e9 + 7, K = 4, iv2 = (P + 1) / 2,
                iv6 = (P + 1) / 6;
long long qpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % P;
    b >>= 1;
    a = a * a % P;
  }
  return ret;
}
void inc(long long &a, long long b) {
  a += b;
  a >= P ? a -= P : 0;
}
long long n, Q;
long long a[N], last[N];
map<long long, long long> vis;
struct Qry {
  long long l, d, id;
};
vector<Qry> q[N];
struct BIT {
  long long c[N];
  void add(long long x, long long v) {
    while (x) {
      inc(c[x], v);
      x -= x & -x;
    }
  }
  long long qry(long long x) {
    long long ret = 0;
    while (x <= n) {
      inc(ret, c[x]);
      x += x & -x;
    }
    return ret;
  }
} T[K];
long long s[N][K];
long long ans[N];
long long qs[N];
long long calc(long long r, long long k) {
  if (k == 0) return r + 1;
  if (k == 1) return r * (r + 1) % P * iv2 % P;
  if (k == 2) return r * (r + 1) % P * (2 * r + 1) % P * iv6 % P;
  if (k == 3) return calc(r, 1) * calc(r, 1) % P;
  return -1;
}
long long C[K][K];
signed main() {
  C[0][0] = 1;
  for (long long i = 1; i < K; i++) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
  }
  scanf("%lld%lld", &n, &Q);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1; i <= Q; i++) {
    long long l, r, d;
    scanf("%lld%lld%lld", &l, &r, &d);
    q[r].push_back({l, d, i});
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0, t = 1; j < K; j++, t = t * a[i] % P)
      s[i][j] = (s[i - 1][j] + t) % P;
    for (auto [l, d, id] : q[i]) {
      long long r = i;
      long long ivd = qpow(d, P - 2);
      for (long long j = 0; j < K; j++)
        qs[j] = (s[r][j] - s[l - 1][j] - T[j].qry(l) + P * 2) % P;
      long long len = qs[0];
      long long sum = qs[1];
      long long st =
          (sum - calc(len - 1, 1) * d % P + P) % P * qpow(len, P - 2) % P;
      if (vis[st] < l && a[i] != st) continue;
      long long ok = 1;
      for (long long j = 2, pd = d * d % P; j < K; j++, pd = pd * d % P) {
        long long sum = 0;
        for (long long p = 0, pst = 1, pdd = pd; p <= j;
             p++, pst = pst * st % P, pdd = pdd * ivd % P)
          inc(sum, C[j][p] * pst % P * pdd % P * calc(len - 1, j - p) % P);
        if (sum != qs[j]) {
          ok = 0;
          break;
        }
      }
      if (ok) ans[id] = 1;
    }
    for (long long j = 0, t = 1; j < K; j++, t = t * a[i] % P)
      T[j].add(vis[a[i]], t);
    vis[a[i]] = i;
  }
  for (long long i = 1; i <= Q; i++) puts(ans[i] ? "Yes" : "No");
}
