#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int N = (int)5e7;
int T;
int n, m;
char a[505], b[505];
int pi[505], poz[505][2];
int16_t dp[505][505][505];
void precalc() {}
void solve() {
  cin >> n >> m >> (a + 1) >> (b + 1);
  int p = 0;
  for (int i = 2; i <= m; i++) {
    while (p && b[p + 1] != b[i]) p = pi[p];
    if (b[p + 1] == b[i]) p++;
    pi[i] = p;
  }
  for (int i = 0; i <= m; i++) {
    for (char c = '0'; c <= '1'; c++) {
      p = i;
      while (p && b[p + 1] != c) p = pi[p];
      if (b[p + 1] == c) p++;
      poz[i][c - '0'] = p;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= m; k++) dp[i][j][k] = static_cast<int16_t>(n + 5);
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= m; k++) {
        for (char c = '0'; c <= '1'; c++) {
          int k2 = poz[k][c - '0'];
          dp[i + 1][j + (k2 == m)][k2] =
              min(dp[i + 1][j + (k2 == m)][k2],
                  static_cast<int16_t>(dp[i][j][k] + (a[i + 1] != c)));
        }
      }
    }
  }
  for (int i = 0; i <= n - m + 1; i++) {
    int16_t ans = n + 5;
    for (int j = 0; j <= m; j++) ans = min(ans, dp[n][i][j]);
    cout << (ans == n + 5 ? -1 : ans) << " ";
  }
  cout << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  precalc();
  for (; T; T--) {
    solve();
  }
  return 0;
}
