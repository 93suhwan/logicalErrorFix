#include <bits/stdc++.h>
using namespace std;
int t, n, a[110];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
signed main() {
  t = read();
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i]) {
        if (a[i - 1])
          ans += 5;
        else
          ans++;
      } else {
        if (!a[i - 1] && i > 1) {
          ans = -1;
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
}
