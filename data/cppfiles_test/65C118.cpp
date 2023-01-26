#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n, m, prim[200050], mu[200050], cnt, tt, vis[200500];
long long dp[55][100500], l[500500], r[505000], ll[500500], rr[500500], ans,
    tot[500500];
void prime(long long n) {
  mu[1] = 1;
  for (register int i = 2; i <= 100000; i++) {
    if (!vis[i]) prim[++cnt] = i, mu[i] = -1;
    for (int j = 1; j <= cnt && prim[j] * i <= n; j++) {
      vis[i * prim[j]] = 1;
      if (i % prim[j] == 0)
        break;
      else
        mu[i * prim[j]] = -mu[i];
    }
  }
}
void work(int k) {
  if (mu[k] == 0) return;
  for (int i = 1; i <= n; i++) {
    ll[i] = (l[i] - 1) / k + 1;
    rr[i] = r[i] / k;
    if (ll[i] > rr[i]) return;
  }
  int tt = m / k;
  for (int j = 0; j <= m / k; j++) tot[j] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m / k; j++) dp[i][j] = 0;
  }
  for (int i = ll[1]; i <= rr[1]; i++) {
    dp[1][i] = 1;
  }
  tot[0] = 0;
  for (int j = 1; j <= m / k; j++) tot[j] = tot[j - 1] + dp[1][j];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= tt; j++) {
      dp[i][j] =
          (tot[max(j - ll[i], 0ll)] - tot[max(j - rr[i] - 1, 0ll)] + mod) % mod;
    }
    tot[0] = 0;
    for (int j = 1; j <= m / k; j++) tot[j] = (tot[j - 1] + dp[i][j]) % mod;
  }
  for (int i = 1; i <= tt; i++) {
    ans = (ans + 1ll * mu[k] * dp[n][i] + mod) % mod;
  }
}
int main() {
  prime(200000);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &l[i], &r[i]);
  }
  for (int i = 1; i <= m; i++) {
    work(i);
  }
  cout << ans;
}
