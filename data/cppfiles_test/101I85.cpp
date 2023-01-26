#include <bits/stdc++.h>
using namespace std;
struct _IO {
  _IO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
} _io;
const long long maxn = 2e5 + 10, mod = 1e9 + 7;
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
long long a[maxn];
char b[maxn];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  cin >> b + 1;
  bool ok = 1;
  long long cntr = 0, cntb = 0;
  for (long long i = 1; i <= n; ++i) {
    if (b[i] == 'B' && a[i] < 1)
      ok = 0;
    else if (b[i] == 'R' && a[i] > n)
      ok = 0;
    else if (a[i] < 1)
      a[i] = 1;
    else if (a[i] > n)
      a[i] = n;
    if (b[i] == 'B' && a[i] == 1) ++cntb;
    if (b[i] == 'R' && a[i] == n) ++cntr;
  }
  if (cntr > 1 || cntb > 1) ok = 0;
  if (!ok)
    cout << "NO\n";
  else
    cout << "YES\n";
}
int main() {
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
