#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 100;
const long long mod = 1e9 + 7;
long long fact[maxn], inv[maxn];
bool vis[maxn];
long long mpow(long long x, long long y) {
  if (!y) return 1;
  long long ret = mpow(x, y / 2);
  ret = ret * ret % mod;
  if (y % 2) ret = ret * x % mod;
  return ret;
}
void init() {}
long long ch(long long n, long long k) {
  return (fact[n] * inv[k] % mod) * inv[n - k] % mod;
}
long long w, h, l, r, u, d, a, b;
void go() {
  cin >> w >> h >> l >> d >> r >> u >> a >> b;
  if (r - l + a > w && u - d + b > h) {
    cout << -1 << endl;
    return;
  }
  long long ans = 1e9;
  if (r - l + a <= w) {
    ans = min(ans, min(a - l, a + r - w));
  }
  if (u - d + b <= h) {
    ans = min(ans, min(b - d, b + u - h));
  }
  ans = max(ans, 0ll);
  double an = ans;
  cout << fixed << setprecision(6) << an << endl;
}
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) go();
  return 0;
}
