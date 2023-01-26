#include <bits/stdc++.h>
using namespace std;
long long dp[505][505];
long long fact[505], nCr[505][505];
void precalc() {
  int i, j;
  fact[0] = 1LL;
  for (i = 1; i <= 500; i++)
    fact[i] = ((fact[i - 1] % 998244353LL) * (i % 998244353LL)) % 998244353LL;
  for (i = 0; i <= 500; i++) {
    nCr[0][i] = 0LL;
    nCr[i][0] = 1LL;
  }
  for (i = 1; i <= 500; i++) {
    for (j = 1; j <= i; j++)
      nCr[i][j] =
          (nCr[i - 1][j] % 998244353LL + nCr[i - 1][j - 1] % 998244353LL) %
          998244353LL;
  }
  return;
}
long long bigmod(long long x, long long n) {
  long long ans = 1LL;
  while (n) {
    if (n % 2LL) ans = ((ans % 998244353LL) * (x % 998244353LL)) % 998244353LL;
    n /= 2LL;
    x = ((x % 998244353LL) * (x % 998244353LL)) % 998244353LL;
  }
  return ans;
}
long long solve(int n, int x) {
  if (x <= (n - 1)) {
    return bigmod(x, n);
  }
  if (n == 1) return 0LL;
  if (dp[n][x] != -1LL) return dp[n][x];
  long long ans = bigmod(n - 1, n);
  for (int i = 2; i <= n; i++) {
    long long porer = nCr[n][i];
    porer = ((porer % 998244353LL) * (solve(i, x - (n - 1)) % 998244353LL)) %
            998244353LL;
    long long out = bigmod(n - 1, n - i);
    long long add = ((porer % 998244353LL) * (out % 998244353LL)) % 998244353LL;
    ans = (ans % 998244353LL + add % 998244353LL) % 998244353LL;
  }
  return dp[n][x] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  precalc();
  long long x, ans;
  int i, j, n;
  cin >> n >> x;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= x; j++) dp[i][j] = -1LL;
  }
  ans = solve(n, x);
  cout << ans << endl;
}
