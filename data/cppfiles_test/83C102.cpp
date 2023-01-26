#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 100;
const long double pi = acos(-1.0);
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
inline long long readll() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
int n, f[N], lcp[N][N], a[N], pos[N];
char s[N];
int main() {
  int T = read();
  while (T--) {
    n = read();
    scanf("%s", s + 1);
    for (register int i = 1; i <= n; i++)
      for (register int j = 1; j <= n; j++) lcp[i][j] = 0;
    for (register int i = n - 1; i >= 1; i--) {
      lcp[i][n] = (s[i] == s[n]);
      for (register int j = n - 1; j >= i + 1; j--) {
        if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
      }
    }
    for (register int i = 1; i <= n; i++) a[i] = n - i + 1;
    f[0] = 0;
    for (register int i = 1; i <= n; i++) {
      f[i] = n - i + 1;
      for (register int j = 1; j <= i - 1; j++) {
        int l = lcp[j][i];
        if (i + l > n) continue;
        if (s[i + l] > s[j + l]) f[i] = max(f[i], f[j] + a[i] - l);
      }
    }
    int ans = 0;
    for (register int i = 1; i <= n; i++) ans = max(ans, f[i]);
    printf("%d\n", ans);
  }
  return 0;
}
