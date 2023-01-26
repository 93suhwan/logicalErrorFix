#include <bits/stdc++.h>
using namespace std;
template <class T>
void rd(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
  x *= f;
}
template <class T>
void cmin(T &x, T y) {
  x = min(x, y);
}
template <class T>
void cmax(T &x, T y) {
  x = max(x, y);
}
const long long mod = 998244353;
template <class T>
T add(T x, T y) {
  return x + y >= mod ? x + y - mod : x + y;
}
template <class T>
T sub(T x, T y) {
  return x - y < 0 ? x - y + mod : x - y;
}
template <class T>
T mul(T x, T y) {
  return 1ll * x * y % mod;
}
template <class T>
void Add(T &x, T y) {
  x = (x + y >= mod ? x + y - mod : x + y);
}
template <class T>
void Sub(T &x, T y) {
  x = (x - y < 0 ? x - y + mod : x - y);
}
template <class T>
void Mul(T &x, T y) {
  x = 1ll * x * y % mod;
}
template <class T>
T qpow(T a, T b = mod - 2) {
  T ret = 1;
  for (; b; b >>= 1, Mul(a, a))
    if (b & 1) Mul(ret, a);
  return ret;
}
const long long N = 1e5 + 10;
const long long inf = 1e17;
long long T, n, k, dp[N][20];
long long mark[N], tot, pri[N], phi[N], P[N];
void sieve(long long n) {
  phi[1] = 1;
  for (long long i = 2; i <= n; i++) {
    if (!mark[i]) pri[++tot] = i, phi[i] = i - 1;
    for (long long j = 1; j <= tot && i * pri[j] <= n; j++) {
      mark[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
    }
  }
  for (long long i = 1; i <= n; i++) P[i] = P[i - 1] + phi[i];
}
long long c(long long l, long long r) {
  if (l > r) return inf;
  long long ret = 0;
  for (long long i = l, nxt; i <= r; i = nxt + 1) {
    nxt = r / (r / i);
    ret += 1ll * P[r / i] * (nxt - i + 1);
  }
  return ret;
}
void solve(long long k, long long L, long long R, long long l, long long r) {
  if (l > r) return;
  if (L == R) {
    for (long long i = l; i <= r; i++)
      dp[i][k] = dp[L][k - 1] + c(min(i, L) + 1, i);
    return;
  }
  long long mid = (l + r) >> 1, pos = L, cost;
  dp[mid][k] = inf;
  cost = c(min(mid, R) + 1, mid);
  for (long long i = min(mid, R); i >= L; i--) {
    long long cur = dp[i][k - 1] + cost;
    if (cur < dp[mid][k]) dp[mid][k] = cur, pos = i;
    if (cost == inf)
      cost = P[mid / i];
    else
      cost += P[mid / i];
  }
  solve(k, L, pos, l, mid - 1);
  solve(k, pos, R, mid + 1, r);
}
void solve() {
  sieve(N - 10);
  n = N - 10;
  dp[0][0] = 0;
  for (long long i = 1; i <= n; i++) dp[i][0] = inf;
  for (long long i = 1; i <= n; i++) dp[i][1] = 1ll * i * (i - 1) / 2 + i;
  for (long long k = 2; k <= 17; k++) solve(k, 1, n, 1, n);
}
signed main() {
  solve();
  rd(T);
  while (T--) {
    rd(n), rd(k);
    if (k > 17 || (1ll << k) > n)
      printf("%lld\n", n);
    else
      printf("%lld\n", dp[n][k]);
  }
  return 0;
}
