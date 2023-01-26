#include <bits/stdc++.h>
using namespace std;
const int maxl = 200005;
int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -w;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + (ch ^ '0');
    ch = getchar();
  }
  return s * w;
}
int t, n, k, flag;
int a[maxl], b[maxl];
signed main() {
  t = read();
  while (t--) {
    n = read(), k = read() - 1, flag = 1;
    for (int i = 1; i <= n; i++) a[i] = read(), b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    for (int i = 1; i < n; i++) {
      if (a[i + 1] != a[i] + 1) k--;
      if (k < 0) {
        flag = 0;
        break;
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
