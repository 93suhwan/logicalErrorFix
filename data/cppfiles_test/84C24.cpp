#include <bits/stdc++.h>
using namespace std;
const long long maxl = 300005, maxg = 22, maxq = 300005;
long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -w;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = (s << 1) + (s << 3) + (ch ^ '0');
    ch = getchar();
  }
  return s * w;
}
long long t, n, pos;
long long prime[maxl], phi[maxl], pre[maxl], f[maxg][maxl];
struct Querylist {
  long long query_n, query_k;
} lis[maxq];
namespace Math {
bool is_p[maxl];
void get_phi() {
  phi[1] = 1;
  for (long long i = 2; i <= n; i++) {
    if (!is_p[i]) prime[++pos] = i, phi[i] = i - 1;
    for (long long j = 1; j <= pos; j++) {
      long long p = prime[j];
      if (i * p > n) break;
      is_p[i * p] = 1;
      if (i % p)
        phi[i * p] = phi[i] * phi[p];
      else {
        phi[i * p] = phi[i] * p;
        break;
      }
    }
  }
}
void get_pre() {
  for (long long i = 1; i <= n; i++) pre[i] = pre[i - 1] + phi[i];
  for (long long i = 1; i <= n; i++) pre[i] = 2 * pre[i] - 1;
}
long long calc(long long x, long long l, long long r) {
  r = min(r, x);
  if (l > r || l > x) return 0;
  long long tot = 0;
  for (long long i = l; i <= r; i++) {
    long long j = min(x / (x / i), r);
    tot += (pre[x / i] - 1) * (j - i + 1);
    i = j;
  }
  return tot;
}
void work() { get_phi(), get_pre(); }
}  // namespace Math
namespace ducati {
void get_all_in() {
  t = read();
  for (long long i = 1; i <= t; i++) {
    lis[i].query_n = read(), lis[i].query_k = read();
    n = max(n, lis[i].query_n);
  }
}
void DP(long long id, long long l, long long r, long long L, long long R) {
  if (l > r) return;
  long long mid = (l + r) >> 1, sumv = Math::calc(mid, min(R, mid) + 1, mid),
            pos = 0;
  for (long long i = min(R, mid); i >= L; i--) {
    sumv += (pre[mid / i] - 1);
    long long val = f[id - 1][i - 1] + sumv;
    if (val < f[id][mid]) f[id][mid] = val, pos = i;
  }
  DP(id, l, mid - 1, L, pos), DP(id, mid + 1, r, pos, R);
}
void init() {
  for (long long i = 0; i <= log2(n); i++) {
    for (long long j = 1; j <= n; j++) f[i][j] = 200000000000000007;
  }
}
void work() {
  for (long long i = 1; i <= log2(n); i++) DP(i, 1, n, 1, n);
  for (long long i = 1; i <= t; i++) {
    long long N = lis[i].query_n, K = lis[i].query_k, ans = lis[i].query_n;
    if (K <= log2(N)) ans = (f[K][N] / 2) + N;
    printf("%lld\n", ans);
  }
}
void solve() {
  get_all_in();
  Math::work();
  init(), work();
}
}  // namespace ducati
signed main() {
  ducati::solve();
  return 0;
}
