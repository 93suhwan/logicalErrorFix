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
const int MAXN = 200005;
const int MAXM = 4000005;
const int MAXP = 7000000;
const int MX = 20005;
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
       c <= ' ';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
}
inline void reads(char *st) {
  char c;
  for (c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c <= ' ';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
  for (; c > ' ';
       *st++ = c,
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
  *st = 0;
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
vector<int> D[MAXN];
int a[MAXN], phi[MAXN], flag[MAXN], cnt[MAXN], vis[MAXN], n, mx = 0, ans = 0;
int upd(int x, int y) { return x + y >= mods ? x + y - mods : x + y; }
void Init(int n) {
  for (int i = 1; i <= n; ++i) phi[i] = i, D[i].push_back(1);
  for (int i = 2; i <= n; ++i) {
    if (!flag[i]) {
      for (int j = i; j <= n; j += i)
        phi[j] = phi[j] / i * (i - 1), flag[j] = 1;
    }
    for (int j = i; j <= n; j += i) D[j].push_back(i);
  }
}
signed main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]), upmax(mx, a[i]);
  Init(mx);
  for (int d = 1; d <= n; ++d) {
    for (int i = d; i <= n; i += d)
      for (auto v : D[a[i]]) ++cnt[v];
    for (int i = d; i <= n; i += d)
      for (auto v : D[a[i]])
        if (vis[v] < d)
          ans = upd(ans, 1ll * cnt[v] * cnt[v] % mods * phi[v] % mods * phi[d] %
                             mods),
          cnt[v] = 0, vis[v] = d;
  }
  print(ans);
  return 0;
}
