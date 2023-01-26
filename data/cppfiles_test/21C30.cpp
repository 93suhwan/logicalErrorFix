#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937_64 rnd;
const long long maxn = 1e2 + 10;
const long long mod = 1e9 + 7;
const long long base = 3e18;
long long c[maxn][maxn];
long long n, m, k, p;
long long dp[maxn][maxn][maxn];
long long gt[maxn];
long long f(long long n, long long m, long long k) {
  assert(n >= k);
  if (n == 0) {
    return 1;
  }
  if (m == 1) {
    return (k == 1 ? gt[n] : 0ll);
  }
  if (dp[n][m][k] != -1) return dp[n][m][k];
  long long ans = 0;
  for (long long sz = 0; sz < n; sz++) {
    long long h = 0;
    for (long long j = max(0ll, k - n + sz + 1); j <= min(sz, k); j++) {
      h = (h + f(sz, m - 1, j) * f(n - 1 - sz, m - 1, k - j)) % p;
    }
    h = (h * c[n - 1][sz]) % p;
    ans = (ans + h) % p;
  }
  return dp[n][m][k] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("SPERFECT.inp", "r")) {
    freopen("SPERFECT.inp", "r", stdin);
    freopen("SPERFECT.out", "w", stdout);
  }
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> k >> p;
  c[0][0] = 1;
  gt[0] = 1;
  for (long long i = 1; i < maxn; i++) {
    gt[i] = (gt[i - 1] * i) % p;
    for (int j = 0; j <= i; j++) {
      if (i == 0 && j == 0) continue;
      c[i][j] = c[i - 1][j];
      if (j) c[i][j] = (c[i][j] + c[i - 1][j - 1]) % p;
    }
  }
  cout << f(n, m, k) << "\n";
}
