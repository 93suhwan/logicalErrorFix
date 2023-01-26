#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long powm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * 1ll * a % 1000000007;
    a = a * 1ll * a % 1000000007;
    b >>= 1;
  }
  return res;
}
long long mul(long long x, long long y) { return (x * 1ll * y) % 1000000007; }
void solve() {
  long long i = 0, j = 0, k = 0, n = 0, m = 0, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  if (rd >= rb && cd >= cb) {
    {
      cout << min((rd - rb), (cd - cb)) << "\n";
      return;
    };
  }
  if (cd >= cb) {
    cout << min((n - rb) * 2 + abs(rb - rd), (cd - cb)) << "\n";
    return;
  };
  if (rd >= rb) {
    cout << min((m - cb) * 2 + abs(cb - cd), (rd - rb)) << "\n";
    return;
  };
  {
    cout << min((((n - rb) * 2) + abs(rb - rd)), ((m - cb) * 2 + abs(cb - cd)))
         << "\n";
    return;
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout << setprecision(15);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
