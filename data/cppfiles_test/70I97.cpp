#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long cum1[200005], cum2[200005];
long long inv(long long a, long long b = MOD) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
long long s1(long long i) { return i * (i + 1) / 2 % MOD; }
long long s2(long long i) {
  return ((i * (i + 1) % MOD) * (2 * i + 1) % MOD) * inv(6) % MOD;
}
void solve() {
  long long n, q;
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    x += 1685;
    x %= MOD;
    cum1[i] = (cum1[i - 1] + x) % MOD;
    cum2[i] = (cum2[i - 1] + x * x % MOD) % MOD;
  }
  for (long long i = 0; i < q; i++) {
    long long l, r, d;
    cin >> l >> r >> d;
    long long m = (r - l + 1);
    long long a =
        (cum1[r] - cum1[l - 1] - m * (m - 1ll) / 2 % MOD * d % MOD + MOD * 2) *
        inv(m) % MOD;
    long long sh =
        (1ll * m * a % MOD * a % MOD + m * (m - 1ll) % MOD * d % MOD * a % MOD +
         m * (m - 1ll) * (m * 2 - 1) / 6 % MOD * d % MOD * d % MOD) %
        MOD;
    assert(sh >= 0);
    if (sh == (cum2[r] - cum2[l - 1] + MOD) % MOD)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
