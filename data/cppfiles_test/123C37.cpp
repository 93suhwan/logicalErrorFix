#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
void chkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
void chkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
namespace fastio {
char rbuf[1 << 23], *p1 = rbuf, *p2 = rbuf, wbuf[1 << 23], *p3 = wbuf;
inline char getc() {
  return p1 == p2 &&
                 (p2 = (p1 = rbuf) + fread(rbuf, 1, 1 << 23, stdin), p1 == p2)
             ? -1
             : *p1++;
}
inline void putc(char x) { (*p3++ = x); }
template <typename T>
void read(T &x) {
  x = 0;
  char c = getc();
  T neg = 0;
  while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
  if (neg) x = (~x) + 1;
}
template <typename T>
void recursive_print(T x) {
  if (!x) return;
  recursive_print(x / 10);
  putc(x % 10 ^ 48);
}
template <typename T>
void print(T x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  recursive_print(x);
}
template <typename T>
void print(T x, char c) {
  print(x);
  putc(c);
}
void readstr(char *s) {
  char c = getc();
  while (c <= 32 || c >= 127) c = getc();
  while (c > 32 && c < 127) s[0] = c, s++, c = getc();
  (*s) = 0;
}
void printstr(string s) {
  for (int i = 0; i < s.size(); i++) putc(s[i]);
}
void printstr(char *s) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() { fwrite(wbuf, 1, p3 - wbuf, stdout); }
}  // namespace fastio
const int MAXN = 2e5;
const int INF = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f3fll;
int n, k, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {
  to[++ec] = v;
  nxt[ec] = hd[u];
  hd[u] = ec;
}
int deg[MAXN + 5], fa[MAXN + 5], dfn[MAXN + 5], tim, edt[MAXN + 5],
    rid[MAXN + 5];
void dfs0(int x, int f) {
  fa[x] = f;
  rid[dfn[x] = ++tim] = x;
  for (int e = hd[x]; e; e = nxt[e]) {
    int y = to[e];
    if (y == f) continue;
    dfs0(y, x);
  }
  edt[x] = tim;
}
struct node {
  int l, r, lz;
  pair<int, int> mx;
} s[MAXN * 4 + 5];
void pushup(int k) { s[k].mx = max(s[k << 1].mx, s[k << 1 | 1].mx); }
void build(int k, int l, int r) {
  s[k].l = l;
  s[k].r = r;
  if (l == r) return s[k].mx = make_pair(-INF, l), void();
  int mid = l + r >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  pushup(k);
}
void tag(int k, int v) {
  s[k].lz += v;
  s[k].mx.first += v;
}
void pushdown(int k) {
  if (s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = 0;
}
void modify(int k, int l, int r, int v) {
  if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
  pushdown(k);
  int mid = s[k].l + s[k].r >> 1;
  if (r <= mid)
    modify(k << 1, l, r, v);
  else if (l > mid)
    modify(k << 1 | 1, l, r, v);
  else
    modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
  pushup(k);
}
void assign(int k, int p, int v) {
  if (s[k].l == s[k].r) return s[k].mx.first = v, void();
  pushdown(k);
  int mid = s[k].l + s[k].r >> 1;
  (p <= mid) ? assign(k << 1, p, v) : assign(k << 1 | 1, p, v);
  pushup(k);
}
bool vis[MAXN + 5];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    adde(u, v);
    adde(v, u);
    deg[u]++;
    deg[v]++;
  }
  dfs0(1, 0);
  int sum = 0;
  for (int i = 2; i <= n; i++) sum += (deg[i] == 1);
  build(1, 1, n);
  for (int i = 2; i <= n; i++)
    if (deg[i] == 1) assign(1, dfn[i], 0);
  for (int i = 1; i <= n; i++) modify(1, dfn[i], edt[i], 1);
  int W = 0, lim = min(sum, k);
  for (int i = 1; i <= lim; i++) {
    pair<int, int> pp = s[1].mx;
    int pt = rid[pp.second];
    assign(1, pp.second, -INF);
    while (pt && !vis[pt])
      vis[pt] = 1, modify(1, dfn[pt], edt[pt], -1), pt = fa[pt], W++;
  }
  long long res = INFll;
  for (int B = 0; B <= n - W; B++) chkmin(res, 1ll * (lim - B) * (n - lim - B));
  if (sum <= k) {
    for (int i = sum; i <= k; i++) chkmax(res, 1ll * i * (n - i));
  }
  printf("%lld\n", res);
  return 0;
}
