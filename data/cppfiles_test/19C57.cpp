#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, ff = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') ff = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ '0');
    c = getchar();
  }
  return x * ff;
}
const int mn = 1000;
int t, n, a[10005];
bool b[2][2005];
bool ok(int m) {
  memset(b, 0, sizeof(b));
  for (register int i = 0; i <= m - a[1]; i++) b[1][i] = 1;
  for (register int i = m; i >= a[1]; i--) b[1][i] = 1;
  for (register int i = 2; i <= n; i++) {
    for (register int k = 0; k <= m; k++) {
      if (k + a[i] <= m) b[i & 1][k + a[i]] |= b[(i & 1) ^ 1][k];
      if (k - a[i] >= 0) b[i & 1][k - a[i]] |= b[(i & 1) ^ 1][k];
      b[(i & 1) ^ 1][k] = 0;
    }
  }
  for (register int i = 0; i <= m; i++)
    if (b[n & 1][i]) return 1;
  return 0;
}
int main() {
  t = read();
  while (t--) {
    n = read();
    for (register int i = 1; i <= n; i++) a[i] = read();
    int l = a[1], r = 2000, mid;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (ok(mid)) {
        r = mid - 1;
      } else
        l = mid + 1;
    }
    cout << l << endl;
  }
  return 0;
}
