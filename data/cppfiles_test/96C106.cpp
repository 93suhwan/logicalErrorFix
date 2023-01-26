#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long mod = 998244353;
const long long N = 505;
long long fact[N], infact[N];
long long mpow(long long x, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (ll)res * x % mod;
    x = (ll)x * x % mod;
    k >>= 1;
  }
  return res;
}
void init(long long a) {
  fact[0] = infact[0] = 1;
  for (long long i = 1; i <= a; i++) {
    fact[i] = (ll)fact[i - 1] * i % mod;
    infact[i] = (ll)infact[i - 1] * mpow(i, mod - 2) % mod;
  }
}
long long C(long long a, long long b) {
  if (a < b) return 0;
  return (ll)fact[a] * infact[a - b] % mod * infact[b] % mod;
}
long long dp[505][505];
long long dfs(long long n, long long x) {
  if (n == 1) return 0ll;
  if (dp[n][x]) return dp[n][x];
  if (x <= n - 1) {
    return dp[n][x] = mpow(x, n);
  }
  long long ans = mpow(n - 1, n);
  for (long long i = 1; i <= n; i++) {
    ans += C(n, i) * mpow(n - 1, n - i) % mod * dfs(i, x - (n - 1)) % mod;
    ans %= mod;
  }
  return dp[n][x] = ans;
}
long long n, x;
void solve() {
  cin >> n >> x;
  init(500);
  cout << dfs(n, x) << "\n";
}
signed main() {
  long long T = 1;
  while (T--) {
    solve();
  }
}
