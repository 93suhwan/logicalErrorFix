#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, k = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') k = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * k;
}
long long a[200005], n, k, presum[200005];
signed main() {
  long long T = read(), sum = 0;
  while (T--) {
    n = read(), k = read();
    for (long long i = 1; i <= n; ++i) {
      a[i] = read();
      sum += a[i];
    }
    if (sum <= k) {
      puts("0");
      continue;
    }
    sort(a + 1, a + n + 1);
    for (long long i = 1; i <= n; ++i) presum[i] = presum[i - 1] + a[i];
    long long ans = 9999999999;
    for (long long i = 0; i < n; ++i) {
      long long temp = a[1] - floor((k - presum[n - i] + a[1]) * 1.0 / (i + 1));
      ans = min(ans, i + max(0ll, temp));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
