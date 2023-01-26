#include <bits/stdc++.h>
using namespace std;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int iINF = INT_MAX;
const long long INF = LLONG_MAX;
const long double PI = 3.14159265358979323846;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fpow(long long a, long long b, long long m) {
  if (!b) return 1;
  long long ans = fpow(a * a % m, b / 2, m);
  return (b % 2 ? ans * a % m : ans);
}
long long inv(long long a, long long m) { return fpow(a, m - 2, m); }
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long n = abs(a - b);
  if (n * 2 < max(a, max(b, c))) {
    cout << "-1\n";
    return;
  }
  if (c >= n + 1) {
    long long ans = c % n;
    if (ans == 0) ans += n;
    cout << ans << "\n";
  } else {
    cout << c + n << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}
