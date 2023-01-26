#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
void _do(T x) {
  cerr << x << "\n";
}
template <typename T, typename... U>
void _do(T x, U... y) {
  cerr << x << ", ";
  _do(y...);
}
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 3e18;
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
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k, r, c, x1, x2, y1, y2;
  cin >> n >> m >> k >> r >> c >> x1 >> y1 >> x2 >> y2;
  long long l = max(x1, x2), R = min(x1 + r - 1, x2 + r - 1);
  long long b = max(y1, y2), t = min(y1 + c - 1, y2 + c - 1);
  long long tmp = 0;
  if (l <= R && b <= t) tmp = (R - l + 1) * (t - b + 1);
  if (tmp == 0) {
    cout << fpow(k, n * m - r * c, MOD1);
  } else {
    long long a = abs(x1 - x2) + 1, B = abs(y1 - y2) + 1;
    long long x = R - l + 1, y = t - b + 1;
    long long tot = r * c;
    if (a <= x && B <= y) tot -= (x - a + 1) * (y - B + 1);
    cout << fpow(k, n * m - tot, MOD1);
  }
}
