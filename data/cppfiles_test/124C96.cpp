#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010, ADD = 2002, mod = 1e9 + 7;
int T, n;
char s[MAXN], t[MAXN];
int f[MAXN][2 * MAXN], g[MAXN][2 * MAXN];
int check(int flag, int i, int j) {
  if (flag == 0) {
    if (s[i] == '?' || s[i] == '0' + j)
      return 1;
    else
      return 0;
  } else {
    if (t[i] == '?' || t[i] == '0' + j)
      return 1;
    else
      return 0;
  }
}
void solve() {
  scanf("%d%s%s", &n, s + 1, t + 1);
  for (int i = (1); i <= (n); i++) {
    if ((i & 1)) continue;
    if (s[i] == '0')
      s[i] = '1';
    else if (s[i] == '1')
      s[i] = '0';
    if (t[i] == '0')
      t[i] = '1';
    else if (t[i] == '1')
      t[i] = '0';
  }
  for (int i = (0); i <= (n + 1); i++)
    for (int j = (-n); j <= (n); j++) f[i][j + ADD] = g[i][j + ADD] = 0;
  f[0][ADD] = g[n + 1][ADD] = 1;
  for (int i = (0); i <= (n - 1); i++) {
    for (int j = (-n); j <= (n); j++) {
      for (int x = (0); x <= (1); x++)
        for (int y = (0); y <= (1); y++) {
          if (!check(0, i + 1, x) || !check(1, i + 1, y)) continue;
          f[i + 1][j + x - y + ADD] =
              (f[i + 1][j + x - y + ADD] + f[i][j + ADD]) % mod;
        }
    }
  }
  for (int i = (n + 1); i >= (2); i--) {
    for (int j = (-n); j <= (n); j++) {
      for (int x = (0); x <= (1); x++)
        for (int y = (0); y <= (1); y++) {
          if (!check(0, i - 1, x) || !check(1, i - 1, y)) continue;
          g[i - 1][j + x - y + ADD] =
              (g[i - 1][j + x - y + ADD] + g[i][j + ADD]) % mod;
        }
    }
  }
  long long ans = 0;
  for (int i = (1); i <= (n); i++) {
    for (int j = (-i); j <= (i); j++) {
      long long ret = abs(j);
      ret = ret * f[i][j + ADD] % mod * g[i + 1][-j + ADD] % mod;
      ans = (ans + ret) % mod;
    }
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
