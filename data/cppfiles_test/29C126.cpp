#include <bits/stdc++.h>
using namespace std;
struct _IO {
  _IO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
} _io;
const long long maxn = 1e6 + 10, mod = 1e9 + 7;
template <typename... T>
long long madd(T... args) {
  long long res = 0;
  for (auto i : {args...}) {
    res = (res + ((i % mod + mod) % mod)) % mod;
  }
  return res % mod;
}
template <typename... T>
long long mmul(T... args) {
  long long res = 1;
  for (auto i : {args...}) {
    res = (res * ((i % mod + mod) % mod)) % mod;
  }
  return res % mod;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
long long mpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
long long _inv(long long x) { return mpow(x, mod - 2); }
void solve() {
  long long cnt0 = 0, cnt1 = 0;
  long long n;
  cin >> n;
  long long t;
  while (n--) {
    cin >> t;
    if (t == 1)
      ++cnt1;
    else if (t == 0)
      ++cnt0;
  }
  cout << cnt1 * qpow(2ll, cnt0) << '\n';
}
int main() {
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
