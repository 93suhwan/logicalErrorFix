#include <bits/stdc++.h>
using namespace std;
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
const int maxn = 3010;
const int maxk = 110;
const int mod = 998244353;
int dp[2][maxn][maxn], fac[maxn], invfac[maxn];
int n, k;
int b[maxn];
int upd(int x) { return x + (x >> 31 & mod); }
int add(int x, int y) { return upd(x + y - mod); }
int main() {
  ios_base::sync_with_stdio(0);
  fac[0] = invfac[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
    invfac[i] = pow(fac[i], mod - 2, mod);
  }
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  int now = 0, nxt = 1;
  dp[now][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int be_rk = max(0, b[i] - k);
    int en_rk = min(i + 1, b[i] + k);
    int rbe_rk = i == 0 ? 0 : max(0, b[i - 1] - k);
    int ren_rk = i == 0 ? 0 : min(i, b[i - 1] + k);
    for (int j = 0; j <= i; j++)
      for (int rk = be_rk; rk <= en_rk; rk++)
        if (dp[now][j][rk]) {
          long long tdp = 1ll * (rk + j) * dp[now][j][rk] + dp[nxt][j][rk];
          dp[nxt][j][rk] = tdp % mod;
          dp[nxt][j + 1][rk] += dp[now][j][rk];
          if (dp[nxt][j + 1][rk] >= mod) dp[nxt][j + 1][rk] -= mod;
        }
    for (int j = -1; j <= i + 1; j++) {
      long long sumdp = 0;
      for (int rk = rbe_rk; rk <= min(ren_rk, be_rk - 2); rk++) {
        const int rj = j + be_rk - rk;
        if (rj < 0) break;
        sumdp = (sumdp + dp[now][rj][rk]) * rj;
        sumdp %= mod;
      }
      for (int rk = ren_rk + 1; rk <= be_rk - 2; rk++) {
        sumdp *= j + be_rk - rk;
        sumdp %= mod;
      }
      const int rk_from = max(be_rk, 1);
      const int rk_to = min(en_rk, j + be_rk + 1);
      for (int rk = rk_from; rk <= rk_to; rk++) {
        const int rj = j + be_rk - (rk - 1);
        long long tdp = dp[nxt][rj][rk];
        tdp += sumdp;
        if (rk - 1 >= rbe_rk && rk - 1 <= ren_rk) {
          tdp += dp[now][rj][rk - 1];
          sumdp += dp[now][rj][rk - 1];
        }
        sumdp *= rj;
        if (sumdp > 1ll << 50) sumdp %= mod;
        dp[nxt][rj][rk] = tdp % mod;
      }
    }
    for (int j = 0; j <= i + 1; j++)
      for (int rk = rbe_rk; rk <= ren_rk; rk++) {
        dp[now][j][rk] = 0;
      }
    swap(now, nxt);
  }
  long long ans = 0;
  for (int j = 0; j <= n; j++)
    for (int rk = 0; rk + j <= n; rk++) {
      if (rk > b[n - 1] + k || rk < b[n - 1] - k) continue;
      ans +=
          1ll * dp[now][j][rk] * fac[n - rk] % mod * invfac[n - rk - j] % mod;
      ans %= mod;
    }
  cout << ans << endl;
  return 0;
}
