#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
int n, a[1005];
int f(int x, int y) {
  int s = 0;
  for (int i = (1); i <= (n); i++) {
    int p = 2100000000;
    for (int j = (0); j <= (x); j++)
      for (int k = (0); k <= (y); k++) {
        int w = j + k * 2;
        if (a[i] >= w && (a[i] - w) % 3 == 0) p = min(p, (a[i] - w) / 3);
      }
    s = max(s, p);
  }
  s += x + y;
  return s;
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = (1); i <= (n); i++) a[i] = read();
    int ans = 2100000000;
    for (int i = (0); i <= (2); i++)
      for (int j = (0); j <= (2); j++) ans = min(ans, f(i, j));
    printf("%d\n", ans);
  }
  return 0;
}
