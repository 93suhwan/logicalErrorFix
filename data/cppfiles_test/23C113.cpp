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
const int MAXN = 100005;
const int MAXM = 4000005;
const int MAXP = 7000000;
const int MX = 300000;
const int mods = 1e9 + 7;
const int SZ = 29;
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
       (c == ' ' || c == '\0' || c == '\n' || c == '\r') && c != EOF;
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
       c != ' ' && c != '\0' && c != '\n' && c != '\r' && c != EOF;
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
int n, m;
long long a[MAXN];
vector<long long> solve(int l, int r) {
  if (l > r) return vector<long long>(1);
  int mid = l;
  for (int i = l; i <= r; ++i)
    if (a[i] < a[mid]) mid = i;
  vector<long long> F, L = solve(l, mid - 1), R = solve(mid + 1, r);
  F.clear(), F.resize(min((int)L.size() + (int)R.size(), m + 1));
  for (int i = 0; i < (int)L.size(); ++i) {
    for (int j = 0; j < (int)R.size() && i + j <= m; ++j)
      upmax(F[i + j], L[i] + R[j] + a[mid] * (-i * j * 2));
    for (int j = 0; j < (int)R.size() && i + j + 1 <= m; ++j)
      upmax(F[i + j + 1],
            L[i] + R[j] + a[mid] * (m - (i + 1) * (j + 1) * 2 + 1));
  }
  return F;
}
signed main() {
  read(n), read(m);
  for (int i = 1; i <= n; ++i) read(a[i]);
  vector<long long> Ans = solve(1, n);
  print(Ans[m]), putc('\n');
  return 0;
}
