#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, f = 1;
  char _ch = getchar();
  while (!('0' <= _ch && _ch <= '9')) (_ch == '-') && (f = -1), _ch = getchar();
  while (('0' <= _ch && _ch <= '9')) s = s * 10 + _ch - 48, _ch = getchar();
  return s * f;
}
const long long N = 2e5 + 10, mod = 1e9 + 7;
long long n, m, rb, cb, rd, cd, dr, dc, p, ox, oy;
inline bool inside(long long x, long long l, long long r) {
  return l <= x && x <= r;
}
inline long long qpw(long long x, long long p) {
  long long s = 1;
  for (; p; p >>= 1, x = x * x % mod)
    if (p & 1) s = s * x % mod;
  return s;
}
inline void work() {
  long long T, k, A, aa, bb, sum = 0;
  dr = dc = 1;
  n = read(), m = read(), ox = rb = read(), oy = cb = read(), rd = read(),
  cd = read(), p = read();
  p = p * qpw(100, mod - 2) % mod;
  vector<long long> t;
  if (!inside(rb + dr, 1, n)) dr = -dr;
  long long dr0 = dr;
  if (!inside(cb + dc, 1, m)) dc = -dc;
  long long dc0 = dc;
  for (T = 0; 1; T++) {
    if (!inside(rb + dr, 1, n)) dr = -dr;
    if (!inside(cb + dc, 1, m)) dc = -dc;
    if (rb == ox && cb == oy && dr == dr0 && dc == dc0 && T) {
      break;
    }
    if (rb == rd || cb == cd) t.push_back(T);
    rb += dr, cb += dc;
  }
  k = (long long)t.size();
  A = qpw(mod + 1 - p, k);
  aa = qpw(mod + 1 - A, mod - 2);
  bb = A * qpw(mod + 1 - A, mod - 2) % mod * qpw(mod + 1 - A, mod - 2) % mod;
  for (long long i = 0; i < k; i++) {
    sum = (sum + p * qpw(mod + 1 - p, i) % mod * t[i] % mod * aa % mod) % mod;
    sum = (sum + p * qpw(mod + 1 - p, i) % mod * T % mod * bb % mod) % mod;
  }
  cout << sum << '\n';
}
signed main() {
  long long _t = read();
  while (_t--) work();
  return 0;
}
