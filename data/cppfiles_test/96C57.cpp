#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const double eps = 1e-7;
const int N = 505, mod = 998244353;
long long qp(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res % mod;
}
long long dp[N][N];
long long in[N], inv[N];
long long C(long long a, long long b) {
  if (a < b) return 0;
  return in[a] * inv[b] % mod * inv[a - b] % mod;
}
void solve() {
  long long n, x;
  cin >> n >> x;
  for (int i = 1; i <= x; i++) dp[1][i] = i;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= x; j++) {
      if (j < i) {
        dp[i][j] = 0;
        continue;
      }
      for (int k = 0; k <= i - 1; k++) {
        dp[i][j] = (dp[i][j] +
                    dp[i - k][j - i + 1] * C(i, k) % mod * qp(i - 1, k) % mod) %
                   mod;
      }
    }
  printf("%lld\n", (qp(x, n) - dp[n][x] + mod) % mod);
}
int main() {
  in[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < N; i++) in[i] = in[i - 1] * i % mod;
  for (int i = 1; i < N; i++) inv[i] = qp(in[i], mod - 2) % mod;
  int t;
  t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
