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
int f[500016], x[500016], y[500016];
int main() {
  canhazfast();
  int q;
  cin >> q;
  iota(f, f + 500016, 0);
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t >> x[i];
    if (t == 2) cin >> y[i];
  }
  for (int i = q - 1; i >= 0; --i) {
    if (y[i] == 0)
      x[i] = f[x[i]];
    else
      f[x[i]] = f[y[i]];
  }
  for (int i = 0; i < q; ++i) {
    if (y[i] == 0) cout << x[i] << ' ';
  }
  cout << '\n';
  return 0;
}
