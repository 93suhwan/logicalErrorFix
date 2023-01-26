#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y <= x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x <= y ? x = y, 1 : 0;
}
const long double eps = 1e-9;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 60;
const int MAXN = 1 << 20;
const int MAXM = 4005;
const int MAXP = 7000000;
const int MX = 20;
const int G = 3;
const int mods = 998244353;
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
queue<int> que;
int n, K, nodenum = -1, ch[MAXN][2], a[MAXN], mn[MAXN], mx[MAXN], ans[MAXN],
          len[MAXN], Ans[MAXN];
int Nwnode(int x) {
  int t = ++nodenum;
  len[t] = 1 << x;
  ch[t][0] = ch[t][1] = 0;
  mn[t] = INF, mx[t] = -INF, ans[t] = INF + INF;
  return nodenum;
}
void up(int x) {
  mn[x] = min(mn[ch[x][0]], mn[ch[x][1]] + (len[x] >> 1));
  mx[x] = max(mx[ch[x][0]], mx[ch[x][1]] + (len[x] >> 1));
  ans[x] = min(min(ans[ch[x][0]], ans[ch[x][1]]),
               mn[ch[x][1]] - mx[ch[x][0]] + (len[x] >> 1));
}
void insert(int x) {
  int nw = 1;
  for (int i = K - 1; i >= 0; --i) {
    if (!ch[nw][(x >> i) & 1]) ch[nw][(x >> i) & 1] = Nwnode(i);
    nw = ch[nw][(x >> i) & 1], a[i] = nw;
  }
  mn[nw] = mx[nw] = 0;
  for (int i = 1; i < K; ++i) up(a[i]);
  up(1);
}
void dfs(int x, int y) {
  if (x == K) {
    Ans[y] = ans[1];
    return;
  }
  dfs(x + 1, y);
  auto flip = [&]() {
    que.push(1);
    int num = 0;
    while (!que.empty()) {
      int q = que.front();
      que.pop(), a[++num] = q;
      if (len[q] == (1 << (x + 1))) {
        swap(ch[q][0], ch[q][1]);
        continue;
      }
      if (ch[q][0]) que.push(ch[q][0]);
      if (ch[q][1]) que.push(ch[q][1]);
    }
    while (num) up(a[num--]);
  };
  flip();
  dfs(x + 1, y | (1 << x));
  flip();
}
signed main() {
  read(n), read(K), Nwnode(0), Nwnode(K);
  for (int i = 1, x; i <= n; ++i) read(x), insert(x);
  Ans[0] = ans[1];
  dfs(0, 0);
  for (int i = 0; i < 1 << K; ++i) print(Ans[i]), putc(' ');
  return 0;
}
