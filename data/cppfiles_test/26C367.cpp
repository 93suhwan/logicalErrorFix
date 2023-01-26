#include <bits/stdc++.h>
const double eps = 1e-8;
const double inf = 1e10;
const long long INF = 0x7f7f7f7f;
const long long mod = 1000000007;
const long long N = 100005;
void Main();
using namespace std;
long long t, n;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  Main();
  return 0;
}
inline void Main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long ans = 1;
    for (long long i = 1; i <= 2 * n; ++i) ans = (ans * i) % mod;
    ans = (ans * qpow(2, mod - 2)) % mod;
    cout << ans << endl;
  }
  return;
}
