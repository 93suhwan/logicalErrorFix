#include <bits/stdc++.h>
using namespace std;
int read() {
  int u = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    u = u * 10 + c - 48;
    c = getchar();
  }
  return u;
}
long long Min(long long x, long long y) { return x < y ? x : y; }
long long Max(long long x, long long y) { return x > y ? x : y; }
int t;
char s[2011], s2[2011];
int n, f[2011][4011], g[2011][4011];
long long ans = 0;
int Abs(int x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  t = read();
  while (t) {
    --t;
    n = read();
    scanf("%s%s", s, s2);
    for (int i = 1; i <= n; ++i) {
      if (i % 2) {
        if (s[i - 1] != '?') s[i - 1] = '0' + '1' - s[i - 1];
        if (s2[i - 1] != '?') s2[i - 1] = '0' + '1' - s2[i - 1];
      }
    }
    ans = 0;
    for (int i = 1; i <= n + 1; ++i) {
      for (int j = 1; j <= 4010; ++j) f[i][j] = g[i][j] = 0;
    }
    f[0][2005] = 1;
    for (int i = 1; i <= n; ++i) {
      int b[3], c[3];
      b[0] = c[0] = 0;
      if (s[i - 1] == '?') {
        b[0] = 2;
        b[1] = 1, b[2] = 0;
      } else
        b[++b[0]] = s[i - 1] - '0';
      if (s2[i - 1] == '?') {
        c[0] = 2;
        c[1] = 1, c[2] = 0;
      } else
        c[++c[0]] = s2[i - 1] - '0';
      for (int k = 1; k <= b[0]; ++k)
        for (int k2 = 1; k2 <= c[0]; ++k2) {
          int dx = b[k] - c[k2];
          for (int j = 2005 - i; j <= 2005 + i; ++j) {
            f[i][j] = (f[i][j] + f[i - 1][j - dx]) % 1000000007;
          }
        }
    }
    g[n + 1][2005] = 1;
    for (int i = n; i >= 1; --i) {
      int b[3], c[3];
      b[0] = c[0] = 0;
      if (s[i - 1] == '?') {
        b[0] = 2;
        b[1] = 1, b[2] = 0;
      } else
        b[++b[0]] = s[i - 1] - '0';
      if (s2[i - 1] == '?') {
        c[0] = 2;
        c[1] = 1, c[2] = 0;
      } else
        c[++c[0]] = s2[i - 1] - '0';
      for (int k = 1; k <= b[0]; ++k)
        for (int k2 = 1; k2 <= c[0]; ++k2) {
          int dx = c[k2] - b[k];
          for (int j = 2005 - i; j <= 2005 + i; ++j) {
            g[i][j] = (g[i][j] + g[i + 1][j - dx]) % 1000000007;
          }
        }
    }
    for (int i = 1; i <= n - 1; ++i) {
      for (int j = 2005 - i; j <= 2005 + i; ++j) {
        ans += (long long)Abs(j - 2005) * f[i][j] % 1000000007 * g[i + 1][j] %
               1000000007;
      }
    }
    ans %= 1000000007;
    cout << ans << endl;
  }
  return 0;
}
