#include <bits/stdc++.h>
using namespace std;
long long t, n, b[100010], lcm, a[100010], ans[100010];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; ++i) {
      scanf("%lld", &b[i]);
      a[i] = abs(b[i]);
    }
    if (n & 1) {
      for (long long i = 1; i <= n - 3; i += 2) {
        ans[i] = -b[i + 1];
        ans[i + 1] = b[i];
      }
      lcm = a[n - 1] * a[n - 2] / gcd(a[n - 1], a[n - 2]);
      lcm = lcm * a[n] / gcd(lcm, a[n]);
      ans[n] = -2 * (lcm / b[n]);
      ans[n - 1] = lcm / b[n - 1];
      ans[n - 2] = lcm / b[n - 2];
    } else
      for (long long i = 1; i <= n; i += 2) {
        ans[i] = -b[i + 1];
        ans[i + 1] = b[i];
      }
    for (long long i = 1; i <= n; ++i) printf("%lld ", ans[i]);
    printf("\n");
  }
  return 0;
}
