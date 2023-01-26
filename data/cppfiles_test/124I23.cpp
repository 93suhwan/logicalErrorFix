#include <bits/stdc++.h>
using namespace std;
const int N = 2005, mod = 1e9 + 7;
int n, f[N][2 * N], g[N][2 * N];
string s, t;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
      if (i & 1) {
        if (s[i] != '?') s[i] = '0' + '1' - s[i];
        if (t[i] != '?') t[i] = '0' + '1' - t[i];
      }
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= 2 * n; j++) f[i][j] = g[i][j] = 0;
    g[0][n] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 2 * n; j++) {
        if (!g[i][j]) continue;
        for (int a = 0; a < 2; a++) {
          if (s[i] - '0' != a && s[i] != '?') continue;
          for (int b = 0; b < 2; b++) {
            if (t[i] - '0' != b && t[i] != '?') continue;
            (f[i + 1][j + a - b] +=
             f[i][j] + 1ll * abs(j + a - b - n) * g[i][j] % mod) %= mod;
            (g[i + 1][j + a - b] += g[i][j]) %= mod;
          }
        }
      }
    }
    cout << f[n][n] << endl;
  }
  return 0;
}
