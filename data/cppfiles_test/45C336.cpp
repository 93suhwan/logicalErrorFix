#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, k = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') k = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * k;
}
const int N = 1e6, inf = 1e9;
int t, n, m;
int a[N];
signed main() {
  t = read();
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int p = 0, num = 0;
    if (a[1] == 1) num++;
    for (int i = 2; i <= n; i++) {
      if (a[i] == 0 && a[i - 1] == 0) {
        printf("-1\n");
        p = 1;
        break;
      }
      if (a[i] == 1 && a[i - 1] == 0) num += 1;
      if (a[i] == 1 && a[i - 1] == 1) num += 5;
    }
    if (p) continue;
    printf("%d\n", num + 1);
  }
  return 0;
}
