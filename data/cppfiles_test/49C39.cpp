#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int r = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) r = r * 10 + (c & 15), c = getchar();
  return r * f;
}
inline void write(int x) {
  char c[20], len = 0;
  if (!x) {
    putchar('0');
    return;
  }
  if (x < 0) x = -x, putchar('-');
  while (x) c[len++] = x % 10, x /= 10;
  while (len) putchar(c[--len] + 48);
}
const int mod = 1e9 + 7;
struct M {
  int x;
  inline M(int a = 0) : x(a) {}
  inline M operator+(const M& p) const {
    return x + p.x >= mod ? x + p.x - mod : x + p.x;
  }
  inline M operator-() const { return x ? mod - x : 0; }
  inline M operator-(const M& p) const {
    return x - p.x < 0 ? x - p.x + mod : x - p.x;
  }
  inline M operator*(const M& p) const { return (long long)x * p.x % mod; }
  inline bool operator==(const int& p) const { return x == p; }
  inline void operator+=(const M& p) { *this = *this + p; }
  inline void operator-=(const M& p) { *this = *this - p; }
  inline void operator*=(const M& p) { *this = *this * p; }
};
inline void write(const M& x) { write(x.x); }
inline M qpow(M x, int y) {
  M res = 1;
  for (; y; y >>= 1) y & 1 ? (res = res * x) : 1, x *= x;
  return res;
}
inline M inv(M x) { return qpow(x, mod - 2); }
const int N = 14, L = 1 << 14;
int n, lg[L];
M a[N], p[N][N], f[N][L], h[N][L];
inline M G(int S, int T) {
  M res = 1;
  while (S) res *= h[lg[S & -S]][T], S ^= S & -S;
  return res;
}
int main() {
  n = read();
  for (int i = 0; i < n; ++i) a[i] = read();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i ^ j) p[i][j] = a[i] * inv(a[i] + a[j]);
  int all = (1 << n) - 1;
  for (int i = 2; i <= all; ++i) lg[i] = lg[i >> 1] + 1;
  for (int i = 0; i < n; ++i) {
    h[i][0] = 1;
    for (int S = 1; S <= all; ++S)
      if (S >> i & 1 ^ 1) h[i][S] = h[i][S ^ (S & -S)] * p[lg[S & -S]][i];
  }
  for (int i = 0; i < n; ++i)
    for (int S = 1; S <= all; ++S)
      if (S >> i & 1) {
        f[i][S] = 1;
        for (int T = (S - 1) & S; T; T = (T - 1) & S)
          if (T >> i & 1) f[i][S] -= f[i][T] * G(T, S ^ T);
      }
  M ans = 0;
  for (int i = 0; i < n; ++i) ans += f[i][all];
  write(ans), putchar('\n');
}
