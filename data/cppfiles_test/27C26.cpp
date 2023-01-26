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
  while (c < 48 || c > 49) c = getchar();
  return c & 1;
}
inline int min(int a, int b) { return a > b ? b : a; }
inline int max(int a, int b) { return a < b ? b : a; }
char a[100005], b[100005];
signed main() {
  int T = read();
  for (int p = 1; p <= (T); p++) {
    scanf("%s%s", a, b);
    int n = strlen(a), m = strlen(b);
    int i = n - 1, j = m - 1;
    if (n < m) goto no;
    while (1) {
      while (a[i] != b[j]) {
        i -= 2;
        if (i < 0) goto no;
      }
      i--, j--;
      if (j == -1) goto yes;
    }
  yes:;
    puts("YES");
    continue;
  no:;
    puts("NO");
  }
  return 0;
}
