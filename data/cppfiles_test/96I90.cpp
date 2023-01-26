#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 998244353;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x = mod - 2) {
  long long ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T &N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
template <class T, class... T_>
inline void re(T &x, T_ &...y) {
  re(x), re(y...);
}
int m, n, t = 1, st, en;
long long mul[N], inv[N];
void C_init() {
  mul[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) mul[i] = mul[i - 1] * i % mod;
  inv[N - 1] = q_pow(mul[N - 1], mod - 2);
  for (int i = N - 2; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
inline long long C(int m, int n) {
  if (m < 0 || m > n) return 0;
  return mul[n] * inv[m] % mod * inv[n - m] % mod;
}
void pre(pair<long long, int> &now, int m, int n) {
  (now.first <<= 1) %= mod;
  now.second++;
  if (now.second >= 0) {
    (now.first += mod - C(now.second - 1, n - 1)) %= mod;
    if (now.second <= m)
      (now.first += C(now.second, n)) %= mod;
    else
      now.second--;
  }
}
long long dp[510][510];
long long dfs(int n, int x) {
  if (n == 1) return 0;
  if (n == 0) return 1;
  if (~dp[n][x]) return dp[n][x];
  if (x <= n - 1) return dp[n][x] = q_pow(x, n);
  long long &ans = dp[n][x] = 0;
  x -= n - 1;
  for (int i = 0; i < n; i++) {
    long long tmp = C(i, n) * q_pow(n - 1, i) % mod;
    (ans += tmp * dfs(n - i, x));
  }
  (ans += q_pow(n - 1, n)) %= mod;
  return ans;
}
int main() {
  memset(dp, -1, sizeof(dp));
  C_init();
  re(n, m);
  printf("%lld\n", dfs(n, m));
}
