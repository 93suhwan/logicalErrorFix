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
long long n, a[1010], ans, fb, sum, x, y;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) continue;
    sum = 0;
    fb = 0;
    for (int j = i + 1; j <= n; j++) {
      if (j % 2 == 1) {
        sum += a[j];
        continue;
      }
      if (sum > a[j]) {
        sum -= a[j];
        continue;
      }
      x = a[j] - sum;
      y = a[i] - fb;
      ans += min(x, y);
      if (fb > 0) ans++;
      fb += x;
      sum = 0;
      if (fb > a[i]) break;
    }
  }
  cout << ans << endl;
  return 0;
}
