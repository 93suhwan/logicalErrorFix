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
signed main() {
  int n = read();
  double c;
  scanf("%lf", &c);
  for (int i = 0; i <= n; i++) {
    double x = 0;
    x += 1.0 * i * (i - 1) * (i - 2) / n / (n - 1) / (n - 2);
    x += 1.0 * i * (i - 1) * (n - i) / n / (n - 1) / (n - 2) * 3;
    x += 0.5 * (n - i) * (n - i - 1) * i / n / (n - 1) / (n - 2) * 3;
    if (x + 1e-9 >= c) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}
