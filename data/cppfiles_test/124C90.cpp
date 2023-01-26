#include <bits/stdc++.h>
using std::cin;
using std::cout;
int const mod = 1e9 + 7;
int f[2010][4010], g[2010][4010];
void solve() {
  int n;
  std::string s, t;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++)
    if (i & 1) {
      if (s[i] != '?') s[i] = (s[i] == '0' ? '1' : '0');
      if (t[i] != '?') t[i] = (t[i] == '0' ? '1' : '0');
    }
  f[0][n] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2 * n; j++) f[i][j] = g[i][j] = 0;
    for (int j = 0; j <= 2 * n; j++)
      for (int x = '0'; x <= '1'; x++)
        if (s[i - 1] == x || s[i - 1] == '?')
          for (int y = '0'; y <= '1'; y++)
            if (t[i - 1] == y || t[i - 1] == '?') {
              int nw = j + x - y;
              f[i][nw] = (f[i][nw] + f[i - 1][j]) % mod;
              g[i][nw] =
                  (g[i][nw] + 1ll * (j - n > 0 ? j - n : n - j) * f[i - 1][j] +
                   g[i - 1][j]) %
                  mod;
            }
  }
  f[0][n] = 0;
  cout << g[n][n] << '\n';
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
