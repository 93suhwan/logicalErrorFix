#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const long long MOD = 998244353;
long long fac[MAXN];
void cal(int range) {
  fac[0] = 1;
  long long ans = 1;
  for (int i = 1; i <= range; i++) {
    ans = (ans * 1ll * i) % MOD;
    fac[i] = ans;
  }
}
long long ksm(long long n, long long x, long long p = MOD) {
  long long ans = 1;
  ans = ans % p;
  while (x) {
    if (x & 1) ans = ans * 1ll * n % p;
    n = n * 1ll * n % p;
    x >>= 1;
  }
  return ans;
}
long long ccc(int x, int y) {
  long long ans = fac[x];
  ans = (ans * ksm(fac[y], MOD - 2, MOD) % MOD) *
        ksm(fac[x - y], MOD - 2, MOD) % MOD;
  return ans;
}
long long dp[500 + 2][500 + 2];
long long c[500 + 2][500 + 2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cal(1000);
  for (int i = 1; i <= 500; i++) {
    for (int j = 1; j <= 500; j++) {
      c[i][j] = ccc(i, j);
    }
  }
  int T;
  T = 1;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (i - 1 >= j)
          dp[i][j] = ksm(j, i);
        else {
          for (int k = 2; k <= i; k++) {
            dp[i][j] +=
                dp[k][j - i + 1] * ksm(i - 1, i - k) % MOD * c[i][k] % MOD;
            dp[i][j] = dp[i][j] % MOD;
          }
          dp[i][j] += ksm(i - 1, i);
          dp[i][j] = dp[i][j] % MOD;
        }
      }
    }
    cout << dp[n][m] << endl;
  }
  return 0;
}
