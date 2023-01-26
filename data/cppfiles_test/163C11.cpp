#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long binpow(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long inv(long long a) { return binpow(a, mod - 2ll); }
long long mulmod(long long a, long long b) { return ((a * b) % mod); }
long long divmod(long long a, long long b) { return ((a * inv(b)) % mod); }
long long addmod(long long a, long long b) { return ((a + b) % mod); }
long long submod(long long a, long long b) { return ((a - b + mod) % mod); }
void solve() {
  int n, m, x, y, a, b, p;
  cin >> n >> m >> x >> y >> a >> b >> p;
  int v1 = 1, v2 = 1;
  p = divmod(100 - p, 100);
  long long tmp = 1;
  long long sum = 0;
  for (int i = 0; i < 4 * (n - 1) * (m - 1); i++) {
    if ((x == 1 and i != 0) or x == n) v1 = -v1;
    if ((y == 1 and i != 0) or y == m) v2 = -v2;
    if (x == a or y == b) {
      tmp = mulmod(tmp, p);
      sum = addmod(sum, tmp);
    } else {
      sum = addmod(sum, tmp);
    }
    x += v1;
    y += v2;
  }
  long long ans = divmod(sum, submod(1, tmp));
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
