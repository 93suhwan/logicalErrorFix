#include <bits/stdc++.h>
namespace infinities {
const long long maxn = 2e6 + 7;
const long long mod = 1e9 + 7;
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long t, n, h[maxn], a[maxn], l, r, mid, b[maxn];
bool ck(long long x) {
  for (register long long i = 1; i <= n; i++) a[i] = h[i], b[i] = h[i];
  for (register long long i = n; i >= 3; i--) {
    register long long d = min(b[i] - x, a[i]) / 3;
    b[i - 1] += d, b[i - 2] += 2 * d, b[i] -= 3 * d;
    ;
  }
  for (register long long i = 1; i <= n; i++)
    if (b[i] < x) return 0;
  return 1;
}
signed main() {
  t = read();
  while (t--) {
    n = read();
    for (register long long i = 1; i <= n; i++) h[i] = read();
    l = 1, r = 1000000000, mid;
    register long long ans = 1;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (ck(mid))
        ans = mid, l = ans + 1;
      else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
}  // namespace infinities
signed main() { return infinities::main(); }
