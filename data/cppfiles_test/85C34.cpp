#include <bits/stdc++.h>
using LL = long long;
const int N = 210;
using namespace std;
int n, mod;
int dp[N][N][40], f[N], inv[N];
int vis[N][N][40];
int a1;
int binpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = (1LL * a * a) % mod)
    if (b & 1) {
      res = (1LL * res * a) % mod;
    }
  return res;
}
int solve(int cur, int sum, int k) {
  if (cur == n) return f[n];
  if (k == 0) return 1LL * f[n] * inv[n - cur] % mod;
  if (vis[cur][sum][k] == a1) return dp[cur][sum][k];
  vis[cur][sum][k] = a1;
  int &res = dp[cur][sum][k];
  res = 0;
  int lim = (a1 - sum) / k;
  for (int cnt = lim; cnt >= 0; cnt--) {
    if (k > 1 && cur + cnt < n - a1 + 2 - k) continue;
    res =
        (res + 1LL * solve(cur + cnt, sum + cnt * k, k - 1) * inv[cnt] % mod) %
        mod;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> mod;
  f[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = 1LL * f[i - 1] * i % mod;
    inv[i] = binpow(f[i], mod - 2);
  }
  int ans = 0;
  int lim = (2 * sqrt(n) + 1);
  for (a1 = max(1, n - lim); a1 <= n; a1++) {
    ans += solve(0, 0, n + 1 - a1);
    ans %= mod;
  }
  cout << ans;
}
