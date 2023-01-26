#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353, N = 505;
int add(int x, int y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
int mul(int x, int y) { return (x * 1ll * y) % MOD; }
int power(int n, int m, int p) {
  int res = 1;
  while (m > 0) {
    if (m & 1) res = (res * 1ll * n) % p;
    n = (n * 1ll * n) % p;
    m /= 2;
  }
  return res;
}
int fact[N], invfact[N];
void init() {
  fact[0] = fact[1] = 1;
  int i;
  for (i = 2; i < N; i++) fact[i] = (fact[i - 1] * 1ll * i) % MOD;
  i--;
  invfact[i] = power(fact[i], MOD - 2, MOD);
  for (i--; i >= 0; i--) invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}
int ncr(int n, int r) {
  if (r > n || n < 0 || r < 0) return 0;
  return mul(fact[n], mul(invfact[r], invfact[n - r]));
}
int dp[N][N];
int calc(int n, int x) {
  if (n == 1) return 0;
  if (x < n) return add(power(x, n, MOD), -power(x - 1, n, MOD));
  if (dp[n][x] == -1) {
    int res = calc(n, x - (n - 1));
    for (int i = 1; i < n; i++) {
      int rem = n - i;
      res = add(res, mul(calc(i, x - n + 1),
                         mul(ncr(n, rem), power(n - 1, rem, MOD))));
    }
    dp[n][x] = res;
  }
  return dp[n][x];
}
int solve() {
  int n, x;
  cin >> n >> x;
  memset(dp, -1, sizeof(dp));
  int res = 0;
  for (int i = 1; i <= x; i++) res = add(res, calc(n, i));
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  cout << solve() << "\n";
  return 0;
}
