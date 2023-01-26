#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmin(T &x, T y) {
  x = x < y ? x : y;
  return;
}
template <typename T>
inline void ckmax(T &x, T y) {
  x = x < y ? y : x;
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
char OPUT[100];
inline void print(long long x) {
  if (!x) return putchar('0'), putchar(' '), void();
  if (x < 0) putchar('-'), x = -x;
  long long cnt = 0;
  while (x) OPUT[++cnt] = x % 10, x /= 10;
  for (register long long i = cnt; i >= 1; --i) putchar(OPUT[i] + '0');
  putchar(' ');
  return;
}
const long long N = 1e6 + 10;
struct node {
  long long a, b, w;
} a[N];
inline bool cmp(node a, node b) { return a.a + a.b < b.a + b.b; }
long long b[N << 1], c, n, mx[N << 2], tag[N << 2], d;
inline void push_down(long long p) {
  if (!tag[p]) return;
  mx[p << 1] += tag[p];
  mx[p << 1 | 1] += tag[p];
  tag[p << 1] += tag[p];
  tag[p << 1 | 1] += tag[p];
  tag[p] = 0;
  return;
}
inline void push_up(long long p) { mx[p] = max(mx[p << 1], mx[p << 1 | 1]); }
inline void push(long long p, long long l, long long r, long long st,
                 long long ed, long long v) {
  if (st <= l && r <= ed) return tag[p] += v, mx[p] += v, void();
  long long mid = (l + r) >> 1;
  push_down(p);
  if (st <= mid) push(p << 1, l, mid, st, ed, v);
  if (ed > mid) push(p << 1 | 1, mid + 1, r, st, ed, v);
  return push_up(p);
}
inline void insert(long long p, long long l, long long r, long long pos,
                   long long v) {
  if (l == r) return ckmax(mx[p], v);
  long long mid = (l + r) >> 1;
  push_down(p);
  if (pos <= mid)
    insert(p << 1, l, mid, pos, v);
  else
    insert(p << 1 | 1, mid + 1, r, pos, v);
  return push_up(p);
}
inline long long query(long long p, long long l, long long r, long long st,
                       long long ed) {
  if (st <= l && r <= ed) return mx[p];
  long long mid = (l + r) >> 1;
  push_down(p);
  if (ed <= mid) return query(p << 1, l, mid, st, ed);
  if (st > mid) return query(p << 1 | 1, mid + 1, r, st, ed);
  return max(query(p << 1, l, mid, st, ed),
             query(p << 1 | 1, mid + 1, r, st, ed));
}
signed main() {
  n = read();
  d = read();
  for (register long long i = 1; i <= n; ++i) {
    a[i].b = read(), a[i].a = max(d, read()), a[i].w = 1;
    b[++c] = a[i].a;
    b[++c] = a[i].b;
  }
  sort(b + 1, b + c + 1);
  c = unique(b + 1, b + c + 1) - b - 1;
  for (register long long i = 1; i <= n; ++i)
    a[i].a = lower_bound(b + 1, b + c + 1, a[i].a) - b,
    a[i].b = lower_bound(b + 1, b + c + 1, a[i].b) - b;
  sort(a + 1, a + n + 1, cmp);
  for (register long long i = 1; i <= n; ++i) {
    if (b[a[i].b] < d) continue;
    long long mx = query(1, 1, c, 1, min(a[i].a, a[i].b));
    insert(1, 1, c, a[i].a, mx + a[i].w);
    if (a[i].a < a[i].b) {
      push(1, 1, c, a[i].a + 1, a[i].b, a[i].w);
    }
  }
  print(mx[1]);
  return 0;
}
