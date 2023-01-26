#include <bits/stdc++.h>
using namespace std;
const int NR = 2005;
const int mod = 1e9 + 7;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n;
char s1[NR], s2[NR];
int f[NR][NR], g[NR][NR], sf[NR][NR], sg[NR][NR];
int las1[NR], las2[NR];
int calcf(int l1, int l2, int r1, int r2) {
  return (0ll + sf[r1][r2] - sf[r1][l2 - 1] - sf[l1 - 1][r2] +
          sf[l1 - 1][l2 - 1] + mod * 2) %
         mod;
}
int calcg(int l1, int l2, int r1, int r2) {
  return (0ll + sg[r1][r2] - sg[r1][l2 - 1] - sg[l1 - 1][r2] +
          sg[l1 - 1][l2 - 1] + mod * 2) %
         mod;
}
void work() {
  n = read(), scanf("%s%s", s1 + 1, s2 + 1);
  for (int i = 1; i <= n; i += 2) {
    if (s1[i] == '1')
      s1[i] = '0';
    else if (s1[i] == '0')
      s1[i] = '1';
    if (s2[i] == '1')
      s2[i] = '0';
    else if (s2[i] == '0')
      s2[i] = '1';
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) f[i][j] = g[i][j] = sf[i][j] = sg[i][j] = 0;
  int now = 0;
  for (int i = 1; i <= n; i++) {
    las1[i] = now;
    if (s1[i] == '1') now = i;
  }
  now = 0;
  for (int i = 1; i <= n; i++) {
    las2[i] = now;
    if (s2[i] == '1') now = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i] == '0' || s2[j] == '0') {
        sf[i][j] =
            (0ll + sf[i - 1][j] + sf[i][j - 1] - sf[i - 1][j - 1] + mod) % mod;
        sg[i][j] =
            (0ll + sg[i - 1][j] + sg[i][j - 1] - sg[i - 1][j - 1] + mod) % mod;
        continue;
      }
      if (las1[i] == 0 && las2[j] == 0) f[i][j] = 1;
      f[i][j] = (f[i][j] + calcf((las1[i] ? las1[i] : 1),
                                 (las2[j] ? las2[j] : 1), i - 1, j - 1)) %
                mod;
      g[i][j] =
          calcg((las1[i] ? las1[i] : 1), (las2[j] ? las2[j] : 1), i - 1, j - 1);
      g[i][j] = (g[i][j] + 1ll * f[i][j] * abs(i - j) % mod) % mod;
      sf[i][j] = (0ll + sf[i - 1][j] + sf[i][j - 1] - sf[i - 1][j - 1] +
                  f[i][j] + mod) %
                 mod;
      sg[i][j] = (0ll + sg[i - 1][j] + sg[i][j - 1] - sg[i - 1][j - 1] +
                  g[i][j] + mod) %
                 mod;
    }
  }
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      ans = (ans + g[i][j]) % mod;
      if (s2[j] == '1') break;
    }
    if (s1[i] == '1') break;
  }
  printf("%d\n", ans);
}
int main() {
  int T = read();
  while (T--) work();
  return 0;
}
