#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-9;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 60;
const int MAXN = 2000005;
const int MAXM = 4005;
const int MAXP = 7000000;
const int MX = 200000;
const int G = 3;
const int mods = 1e9 + 7;
const int Gi = (mods + 1) / G;
const int SZ = 10;
const int inv2 = (mods + 1) >> 1;
const int INF = 0x3f3f3f3f;
namespace FastIO {
constexpr int SIZE = (1 << 21) + 1;
int num = 0, f;
char ibuf[SIZE], obuf[SIZE], que[65], *iS, *iT, *oS = obuf,
                                                *oT = obuf + SIZE - 1, c;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char c) {
  *oS++ = c;
  if (oS == oT) flush();
}
inline void getc(char &c) {
  for (c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       (c == ' ' || c == '\0' || c == '\n') && c != EOF;
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
}
inline void reads(char *st) {
  char c;
  int n = 0;
  getc(st[++n]);
  for (c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c != ' ' && c != '\0' && c != '\n' && c != EOF;
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    st[++n] = c;
  st[++n] = '\0';
}
template <class I>
inline void read(I &x) {
  for (f = 1, c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = (x << 3) + (x << 1) + (c & 15);
  x *= f;
}
template <class I>
inline void print(I x) {
  if (x < 0) putc('-'), x = -x;
  if (!x) putc('0');
  while (x) que[++num] = x % 10 + 48, x /= 10;
  while (num) putc(que[num--]);
}
inline void putstr(string st) {
  for (int i = 0; i < (int)st.size(); ++i) putc(st[i]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_Flusher_;
}  // namespace FastIO
using FastIO ::getc;
using FastIO ::print;
using FastIO ::putc;
using FastIO ::putstr;
using FastIO ::read;
using FastIO ::reads;
int a[15], Inv[MAXN], fac[MAXN], g[15][1 << 14], f[1 << 14];
int upd(int x, int y) { return x + y >= mods ? x + y - mods : x + y; }
void Init(int n) {
  Inv[0] = Inv[1] = 1;
  for (int i = 2; i <= n; ++i)
    Inv[i] = 1ll * (mods - mods / i) * Inv[mods % i] % mods;
}
signed main() {
  int n;
  read(n), Init(2000000);
  for (int i = 0; i < n; ++i) read(a[i]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 1 << n; ++j) {
      int p = 1;
      for (int k = 0; k < n; ++k)
        if ((j >> k) & 1) p = 1ll * p * a[i] % mods * Inv[a[i] + a[k]] % mods;
      g[i][j] = p;
    }
  }
  int ans = 0, all = (1 << n) - 1;
  for (int i = 0; i <= all; ++i) {
    f[i] = 1;
    for (int j = (i - 1) & i; j; j = (j - 1) & i) {
      int p = 1;
      for (int k = 0; k < n; ++k)
        if ((j >> k) & 1) p = 1ll * p * g[k][i ^ j] % mods;
      f[i] = upd(f[i], mods - 1ll * f[j] * p % mods);
    }
    int p = 1;
    for (int k = 0; k < n; ++k)
      if ((i >> k) & 1) p = 1ll * p * g[k][all ^ i] % mods;
    ans = upd(ans, 1ll * f[i] * p % mods * __builtin_popcount(i) % mods);
  }
  print(ans);
  return 0;
}
