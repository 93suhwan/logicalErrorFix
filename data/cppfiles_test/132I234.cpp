#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
}
long long add(long long x, long long y) {
  long long res = x + y;
  return (res >= 1000000007 ? res - 1000000007 : res);
}
long long mul(long long x, long long y) {
  long long res = x * y;
  return (res >= 1000000007 ? res % 1000000007 : res);
}
long long sub(long long x, long long y) {
  long long res = x - y;
  return (res < 0 ? res + 1000000007 : res);
}
long long power(long long x, long long y) {
  long long res = 1;
  x %= 1000000007;
  while (y) {
    if (y & 1) res = mul(res, x);
    y >>= 1;
    x = mul(x, x);
  }
  return res;
}
long long mod_inv(long long x) { return power(x, 1000000007 - 2); }
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T... args) {
  ((cout << args << ' '), ...);
}
const long long INF = 1000000050;
const long long BIG = (long long)2e18 + 50;
const long long MX = 200010;
const double EPS = 1e-9;
void solve() {
  vector<long long> a(7);
  for (long long &i : a) cin >> i;
  sort(a.begin(), a.end());
  cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long x;
  cin >> x;
  while (x--) {
    solve();
  }
}
