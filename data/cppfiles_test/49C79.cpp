#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int RLEN = 1 << 22 | 1;
char ibuf[RLEN], *ib, *ob;
inline char gc() {
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? EOF : *ib++;
}
inline int read() {
  char ch = gc();
  int res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res * 10) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline long long readll() {
  char ch = gc();
  long long res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res * 10) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline char readchar() {
  char ch = gc();
  while (isspace(ch)) ch = gc();
  return ch;
}
inline int readstring(char *s) {
  int top = 0;
  char ch = gc();
  while (isspace(ch)) ch = gc();
  while (!isspace(ch) && ch != EOF) s[++top] = ch, ch = gc();
  s[top + 1] = '\0';
  return top;
}
}  // namespace IO
using IO::read;
using IO::readchar;
using IO::readll;
using IO::readstring;
template <typename tp>
inline bool chemx(tp &a, tp b) {
  return (a < b) ? (a = b, 1) : 0;
}
template <typename tp>
inline bool chemn(tp &a, tp b) {
  return (a > b) ? (a = b, 1) : 0;
}
const int mod = 1e9 + 7;
inline int add(int a, int b) {
  return (a + b) >= mod ? (a + b - mod) : (a + b);
}
inline int dec(int a, int b) { return (a < b) ? (a - b + mod) : (a - b); }
inline int mul(int a, int b) {
  static long long r;
  r = (long long)a * b;
  return (r >= mod) ? (r % mod) : r;
}
inline void Add(int &a, int b) { a = (a + b) >= mod ? (a + b - mod) : (a + b); }
inline void Dec(int &a, int b) { a = (a < b) ? (a - b + mod) : (a - b); }
inline void Mul(int &a, int b) {
  static long long r;
  r = (long long)a * b;
  a = (r >= mod) ? (r % mod) : r;
}
inline int ksm(int a, int b, int res = 1) {
  for (; b; b >>= 1, Mul(a, a)) (b & 1) && (Mul(res, a), 1);
  return res;
}
inline int Inv(int x) { return ksm(x, mod - 2); }
inline int fix(long long x) {
  x %= mod;
  return (x < 0) ? x + mod : x;
}
const int N = 15, M = (1 << 15) | 5;
int n, a[N], pw[N][N], p1[N][M], f[M], id[M], lim;
inline int lb(int x) { return x & (-x); }
int calc(int s) {}
int main() {
  n = read(), lim = 1 << n;
  for (int i = 1; i <= n; i++)
    a[i] = read(), id[1 << (i - 1)] = i, p1[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i ^ j) pw[i][j] = mul(a[i], Inv(a[i] + a[j]));
  for (int s = 1; s < lim; s++)
    for (int i = 1; i <= n; i++)
      if (!(s & (1 << (i - 1))))
        p1[i][s] = mul(p1[i][s - lb(s)], pw[id[lb(s)]][i]);
  f[0] = 1;
  int res = 0;
  for (int s = 1; s < lim; s++) {
    int pt = 1;
    for (int ss = s; ss; ss = (ss - 1) & s)
      if (ss != s) {
        int ret = 1;
        for (int i = 1; i <= n; i++)
          if (!(s & (1 << (i - 1)))) Mul(ret, p1[i][ss]);
        Dec(pt, mul(f[ss], Inv(ret)));
      }
    int pc = 1;
    for (int i = 1; i <= n; i++)
      if (!(s & (1 << (i - 1)))) Mul(pc, p1[i][s]);
    f[s] = mul(pt, pc);
    Add(res, mul(f[s], __builtin_popcount(s)));
  }
  cout << res << '\n';
  return 0;
}
