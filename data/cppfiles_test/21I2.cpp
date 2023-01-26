#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline", \
                     "03")
const int maxn = 110;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
long long qpow(long long b, int e) {
  if (!e) return 1;
  if (e & 1) return qpow(b, e - 1) * b % mod;
  int pwur = qpow(b, e >> 1);
  return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
long long rng(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(rnd);
}
int p, m, dp[maxn][maxn][maxn], fact[maxn], C[maxn][maxn];
int DP(int sz, int see, int good) {
  if (dp[sz][see][good] != -1) return dp[sz][see][good];
  if (see >= m) return fact[sz] * (good == 0);
  int ans = 0;
  for (int lsz = 0; lsz < sz; lsz++) {
    int rsz = sz - 1 - lsz;
    int tgood = (see + 1 == m);
    if (good - tgood < 0) continue;
    for (int lg = 0; lg <= good - tgood; lg++) {
      int rg = good - tgood - lg;
      ans = (1ll * ans + 1ll * DP(lsz, see + 1, lg) * DP(rsz, see + 1, rg) % p *
                             C[lsz + rsz][lsz]) %
            p;
    }
  }
  return dp[sz][see][good] = ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  int n, k;
  cin >> n >> m >> k >> p;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = 1ll * fact[i - 1] * i % p;
  for (int i = 0; i <= n; i++) C[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) dp[i][j][k] = -1 * (i > 0);
  cout << DP(n, 0, k) << '\n';
  return 0;
}
