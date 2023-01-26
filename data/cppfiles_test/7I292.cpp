#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int T, n;
long long a[N], b[N], f[N], g[N];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n - 1; i++) b[i] = abs(a[i] - a[i + 1]);
    f[1] = 1;
    g[1] = b[1];
    for (int i = 2; i <= n - 1; i++) {
      long long x = gcd(g[i - 1], b[i]);
      if (x == 1) {
        g[i] = b[i];
        f[i] = 1;
      } else {
        g[i] = x;
        f[i] = f[i - 1] + 1;
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n - 1; i++) ans = max(ans, f[i]);
    printf("%lld\n", ans + 1);
  }
  return 0;
}
