#include <bits/stdc++.h>
using namespace std;
int n, m, k, p;
int comb[101][101], fac[101], f[101][101][101];
int dp(int n, int m, int k) {
  if (f[n][m][k] != -1) return f[n][m][k];
  if (n == 0) return k == 0 ? 1 : 0;
  if (m == 1) return k == 1 ? fac[n] : 0;
  if (n == 1) return k == 0;
  int ans = 0;
  for (int i = 0; i <= n - 1; ++i) {
    int temp = 0;
    for (int j = 0; j <= min(i, k); ++j) {
      if (k - j <= n - i - 1)
        temp =
            (temp + 1LL * dp(i, m - 1, j) * dp(n - i - 1, m - 1, k - j) % p) %
            p;
    }
    ans = (ans + 1LL * comb[n - 1][i] * temp % p) % p;
  }
  return f[n][m][k] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k >> p;
  comb[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % p;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = 1LL * i * fac[i - 1] % p;
  }
  memset(f, -1, sizeof(f));
  cout << dp(n, m, k);
}
