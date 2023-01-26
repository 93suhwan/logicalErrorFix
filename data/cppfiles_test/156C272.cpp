#include <bits/stdc++.h>
using namespace std;
const long long NR = 2e5 + 10;
void Min(long long& x, long long y) { x = min(x, y); }
void Max(long long& x, long long y) { x = max(x, y); }
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n, k;
long long a[NR];
void work() {
  n = read(), k = read();
  a[n + 1] = 0;
  for (long long i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  long long sum = 0, ans = 0x3f3f3f3f3f3f3f3fll;
  for (long long i = 2; i <= n; i++) sum += a[i];
  for (long long i = n + 1; i >= 2; i--) {
    sum -= a[i];
    long long p = k - sum;
    long long q = n - i + 2;
    if (p >= 0)
      p = p / q;
    else
      p = (p - q + 1) / q;
    ans = min(ans, n - i + 1 + max(0ll, a[1] - p));
  }
  printf("%lld\n", ans);
}
signed main() {
  long long T = read();
  while (T--) work();
  return 0;
}
