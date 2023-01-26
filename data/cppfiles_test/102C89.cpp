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
const int mod = 998244353;
struct M {
  int x;
  inline M(int a = 0) : x(a % mod) {}
  inline M operator+(const M& p) const {
    return x + p.x >= mod ? x + p.x - mod : x + p.x;
  }
  inline M operator-() const { return x ? mod - x : 0; }
  inline M operator-(const M& p) const {
    return x - p.x < 0 ? x - p.x + mod : x - p.x;
  }
  inline M operator*(const M& p) const { return (long long)x * p.x % mod; }
  inline bool operator==(const M& p) const { return x == p.x; }
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
int k, a[6];
M p[33], h;
const int L[6][6] = {
    {}, {1}, {1, 4}, {1, 6, 16}, {1, 10, 28, 64}, {1, 18, 52, 120, 256}};
const int R[6][6] = {
    {}, {2}, {4, 6}, {8, 12, 20}, {16, 24, 40, 72}, {32, 48, 80, 144, 272}};
int ans[33], win[6][33];
pair<int, int> last;
bool flag = 0;
unordered_map<int, pair<int, int> > mp;
void dfs2(int x) {
  if (!x) {
    if (last == pair<int, int>(win[1][0], win[1][1])) {
      ans[win[1][0]] = 1;
      ans[win[1][1]] = 2;
      flag = 1;
      return;
    }
    if (last == pair<int, int>(win[1][1], win[1][0])) {
      ans[win[1][0]] = 2;
      ans[win[1][1]] = 1;
      flag = 1;
      return;
    }
  }
  int m = 1 << x, s;
  for (int i = 0; i < (1 << m); ++i) {
    s = 0;
    for (int j = 0; j < m; ++j) {
      win[x][j] = win[x + 1][j << 1 | (i >> j & 1)];
      ans[win[x + 1][j << 1 | (i >> j & 1 ^ 1)]] = m + 1;
      s += win[x + 1][j << 1 | (i >> j & 1 ^ 1)];
    }
    if (s == a[x]) dfs2(x - 1);
    if (flag) return;
  }
}
void dfs1(int x, M now) {
  if (!x) {
    if (!mp.count((h - now).x)) return;
    last = mp[(h - now).x];
    dfs2(k - 1);
    if (flag) {
      for (int i = 1; i <= (1 << k); ++i) write(ans[i]), putchar(' ');
      exit(0);
    }
    return;
  }
  for (int i = L[k][x]; i <= R[k][x]; ++i)
    a[x] = i, dfs1(x - 1, now + p[(1 << x) + 1] * i);
}
int main() {
  k = read(), p[1] = read(), h = read();
  for (int i = 2; i <= (1 << k); ++i) p[i] = p[i - 1] * p[1];
  for (int i = 0; i < (1 << k); ++i) win[k][i] = i + 1;
  for (int i = 1; i <= (1 << k); ++i)
    for (int j = 1; j <= (1 << k); ++j)
      if (i ^ j) mp[(p[1] * i + p[2] * j).x] = pair<int, int>(i, j);
  dfs1(k - 1, 0);
  puts("-1");
}
