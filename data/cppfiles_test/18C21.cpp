#include <bits/stdc++.h>
using namespace std;
void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
int ctz(unsigned x) { return __builtin_ctz(x); }
int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
int clz(unsigned x) { return __builtin_clz(x); }
int clzll(unsigned long long x) { return __builtin_clzll(x); }
int popcnt(unsigned x) { return __builtin_popcount(x); }
int popcntll(unsigned long long x) { return __builtin_popcountll(x); }
int bsr(unsigned x) { return 31 ^ clz(x); }
int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
int a[1000016], b[1000016];
void solve() {
  int n, d;
  int k, len, ans = 0;
  cin >> n >> d;
  for (int i = 0; i < n; ++i) cin >> a[i];
  k = gcd(n, d);
  len = n / k;
  for (int i = 0; i < k; ++i) {
    for (int j = 0, p = i; j < len; ++j) {
      b[j] = a[p];
      p += d;
      if (p >= n) p -= n;
    }
    int cnt = 0;
    for (int j = 0; j < len; ++j) {
      if (b[j])
        ans = max(ans, ++cnt);
      else
        cnt = 0;
    }
    for (int j = 0; j < len; ++j) {
      if (b[j])
        ans = max(ans, ++cnt);
      else
        cnt = 0;
    }
  }
  if (ans >= len) ans = -1;
  cout << ans << '\n';
}
int main() {
  canhazfast();
  int t;
  cin >> t;
  for (; t; --t) solve();
  return 0;
}
