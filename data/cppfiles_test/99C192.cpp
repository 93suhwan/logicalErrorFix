#include <bits/stdc++.h>
inline int read() {
  int num = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > 47 && c < 58) num = num * 10 + (c ^ 48), c = getchar();
  return num * f;
}
inline int re1d() {
  char c = getchar();
  while (c < 49 || c > 50) c = getchar();
  return c & 1;
}
inline int min(int a, int b) { return a > b ? b : a; }
inline int max(int a, int b) { return a < b ? b : a; }
char a[51][51];
int s[51], f[51];
signed main() {
  int T = read();
  for (int i = 1; i <= (T); i++) {
    int n = read(), cc = 0;
    for (int i = 1; i <= (n); i++) {
      s[i] = re1d();
      if (!s[i]) f[++cc] = i;
    }
    memset(a, '=', sizeof(a));
    for (int i = 1; i <= (n); i++) {
      a[i][i] = 'X';
    }
    if (cc == 1 || cc == 2) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 1; i <= (cc - 1); i++) {
      a[f[i]][f[i + 1]] = '+', a[f[i + 1]][f[i]] = '-';
    }
    a[f[cc]][f[1]] = '+', a[f[1]][f[cc]] = '-';
    for (int i = 1; i <= (n); i++) {
      for (int j = 1; j <= (n); j++) {
        putchar(a[i][j]);
      }
      putchar(10);
    }
  }
  return 0;
}
