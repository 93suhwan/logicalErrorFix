#include <bits/stdc++.h>
using namespace std;
const long long maxl = 200005;
long long read() {
  long long s = 0, w = 1;
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
long long t, n, k, flag;
long long a[maxl];
signed main() {
  t = read();
  while (t--) {
    n = read(), k = read() - 1, flag = 1;
    for (long long i = 1; i <= n; i++) a[i] = read();
    for (long long i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) k--;
      if (k < 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 0)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
