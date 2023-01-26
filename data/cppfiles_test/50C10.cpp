#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T &x, T y) {
  x = x < y ? y : x;
  return;
}
template <typename T>
inline void ckmin(T &x, T y) {
  x = x < y ? x : y;
  return;
}
inline long long read() {
  long long res = 0, f = 1;
  char k;
  while (!isdigit(k = getchar()))
    if (k == '-') f = -1;
  while (isdigit(k)) res = res * 10 + k - '0', k = getchar();
  return res * f;
}
namespace Output {
char OPUT[100];
inline void print(int x) {
  if (!x) return putchar('0'), putchar('\n'), void();
  if (x < 0) putchar('-'), x = -x;
  int cnt = 0;
  while (x) OPUT[++cnt] = x % 10, x /= 10;
  for (register int i = cnt; i >= 1; --i) putchar(OPUT[i] + '0');
  putchar('\n');
  return;
}
}  // namespace Output
using namespace Output;
const int M = 5e4 + 10, N = M << 6;
int ls[N], rs[N], fa[N], cnt, n, m, ans[M], qcnt, rt, opt[M], tim[N];
char s[10];
long long y[M], x[M];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void push_down(int p) {
  if (!ls[p]) ls[p] = ++cnt, fa[cnt] = cnt;
  if (!rs[p]) rs[p] = ++cnt, fa[cnt] = cnt;
  if (tim[p]) tim[rs[p]] = tim[ls[p]] = tim[p], tim[p] = 0;
  return;
}
vector<pair<int, int> > upd[M];
inline void merge(int x, int y) {
  if (ls[x] + rs[x] + ls[y] + rs[y] == 0)
    return upd[min(tim[x], tim[y])].push_back(make_pair(x, y)), void();
  else if (ls[x] + rs[x] == 0)
    push_down(y), merge(x, ls[y]), merge(x, rs[y]);
  else if (ls[y] + rs[y] == 0)
    push_down(x), merge(ls[x], y), merge(rs[x], y);
  else
    push_down(x), push_down(y), merge(ls[x], ls[y]), merge(rs[x], rs[y]);
  return;
}
inline void push(int p, long long l, long long r, long long st, long long ed,
                 int tmp) {
  if (st <= l && r <= ed) return tim[p] = tmp, void();
  long long mid = (l + r) >> 1;
  push_down(p);
  if (st <= mid) push(ls[p], l, mid, st, ed, tmp);
  if (ed > mid) push(rs[p], mid + 1, r, st, ed, tmp);
  return;
}
inline int getid(int p, long long l, long long r, long long pos) {
  if (ls[p] + rs[p] == 0) return p;
  long long mid = (l + r) >> 1;
  if (pos <= mid)
    return getid(ls[p], l, mid, pos);
  else
    return getid(rs[p], mid + 1, r, pos);
}
signed main() {
  n = read();
  m = read();
  tim[fa[rt = cnt = 1] = 1] = m + 1;
  long long U = 1ll << n;
  --U;
  for (register int i = 1; i <= m; ++i) {
    scanf("%s", s + 1);
    x[i] = read(), y[i] = read();
    if (s[1] == 'b') push(rt, 0, U, x[i], y[i], i), opt[i] = 1;
  }
  for (register int i = 1; i <= cnt; ++i)
    if (ls[i] + rs[i]) merge(ls[i], rs[i]);
  for (auto t : upd[m + 1]) fa[find(t.first)] = find(t.second);
  for (register int i = m; i >= 1; --i) {
    if (opt[i])
      for (auto t : upd[i]) fa[find(t.first)] = find(t.second);
    else
      ans[++qcnt] = find(getid(rt, 0, U, x[i])) == find(getid(rt, 0, U, y[i]));
  }
  reverse(ans + 1, ans + qcnt + 1);
  for (register int i = 1; i <= qcnt; ++i) print(ans[i]);
  return 0;
}
