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
        (((cum1[r] - cum1[l - 1] - s1(m - 1) * d % MOD) % MOD + MOD) * inv(m)) %
        MOD;
    long long sh = sh = m * a % MOD * a % MOD +
                        (2 * d * s1(m - 1) % MOD) * (a) % MOD +
                        (d * d % MOD) * s2(m - 1) % MOD;
    if (sh == (cum2[r] - cum2[l - 1] + MOD) % MOD)
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
