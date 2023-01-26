#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
using ll = long long;
ll mod;
ll C[N][N], f[N][N][N], fac[N];
ll dp(int n, int m, int k) {
  if (k > n || k < 0) return 0;
  if (m == 1) return fac[n] * (k == 1);
  if (n == 1) return m == 1 && k == 1 || m > 1 && k == 0;
  if (m + k - 1 > n) return (!k) ? fac[n] : 0;
  if (f[n][m][k] != -1) return f[n][m][k];
  ll &ret = f[n][m][k];
  ret = 2 * dp(n - 1, m - 1, k) % mod;
  for (register int p = 2; p <= n - 1; p++) {
    for (register int k1 = 0; k1 <= min(k, p - 1); k1++) {
      ret = (ret + C[n - 1][p - 1] * dp(p - 1, m - 1, k1) % mod *
                       dp(n - p, m - 1, k - k1)) %
            mod;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k >> mod;
  for (register int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (register int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  fac[0] = 1;
  for (register int i = 1; i <= n; i++) fac[i] = i * fac[i - 1] % mod;
  memset(f, -1, sizeof f);
  cout << dp(n, m, k) << endl;
  return 0;
}
