#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int a[200010];
signed main() {
  int t = read();
  while (t--) {
    int n = read();
    for (register int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + n + 1);
    int m = n / 2;
    for (register int i = 1; i <= m; ++i) {
      printf("%d %d\n", a[i + 1], a[1]);
    }
  }
  return 0;
}
