#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 50;
const int INF = 1e9;
const int mod = 998244353;
inline long long int qpow(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
inline long long int get_inv(long long int a) { return qpow(a, mod - 2); }
long long int fac[MAXN], inv[MAXN];
void init() {
  fac[0] = 1;
  for (int i = 1; i <= 500; i++) fac[i] = fac[i - 1] * i % mod;
  inv[500] = get_inv(fac[500]);
  for (int i = 499; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long int C(int n, int m) {
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
long long int dp[510][510];
inline void solve() {
  int n, x;
  cin >> n >> x;
  long long int ans = 0;
  for (int i = 0; i <= 500; i++) dp[0][i] = 1;
  for (int i = 0; i <= 500; i++) dp[1][i] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (i - 1 >= j) {
        dp[i][j] = qpow(j, i);
      } else {
        long long int p = 1;
        for (int k = 0; k <= i; k++, p *= (i - 1) % mod) {
          dp[i][j] += C(i, k) * p % mod * dp[i - k][j - i + 1] % mod;
          dp[i][j] %= mod;
        }
      }
    }
  }
  cout << dp[n][x] << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int _ = 1;
  init();
  while (_--) {
    solve();
  }
  return 0;
}
