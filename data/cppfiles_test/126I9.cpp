#include <bits/stdc++.h>
using namespace std;
long long inf;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T, class T2>
long long chkmin(T &a, T2 b) {
  return a > b ? a = b, 1 : 0;
}
template <class T, class T2>
long long chkmax(T &a, T2 b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T, class T2>
T mmin(T a, T2 b) {
  return a < b ? a : b;
}
template <class T, class T2>
T mmax(T a, T2 b) {
  return a > b ? a : b;
}
template <class T>
T aabs(T a) {
  return a < 0 ? -a : a;
}
template <class T>
long long dcmp(T a, T b) {
  return a > b;
}
template <long long *a>
long long cmp_a(long long first, long long second) {
  return a[first] < a[second];
}
template <class T>
bool sort2(T &a, T &b) {
  return a > b ? swap(a, b), 1 : 0;
}
template <class T, class... T2>
T mmin(T a, T2... b) {
  return mmin(a, mmin(b...));
}
template <class T, class... T2>
T mmax(T a, T2... b) {
  return mmax(a, mmax(b...));
}
struct __INIT__ {
  __INIT__() {
    fill((unsigned char *)&inf, (unsigned char *)&inf + sizeof(inf), 0x3f);
  }
} __INIT___;
namespace io {
const long long SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
long long f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char first) {
  *oS++ = first;
  if (oS == oT) flush();
}
template <typename A>
inline bool read(A &first) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-')
      f = -1;
    else if (c == EOF)
      return 0;
  for (first = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    first = first * 10 + (c & 15);
  first *= f;
  return 1;
}
inline bool read(char &first) {
  while ((first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)) == ' ' ||
         first == '\n' || first == '\r')
    ;
  return first != EOF;
}
inline bool read(char *first) {
  while ((*first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                                (iS == iT ? EOF : *iS++))
                             : *iS++)) == '\n' ||
         *first == ' ' || *first == '\r')
    ;
  if (*first == EOF) return 0;
  while (!(*first == '\n' || *first == ' ' || *first == '\r' || *first == EOF))
    *(++first) = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                           : *iS++);
  *first = 0;
  return 1;
}
template <typename A, typename... B>
inline bool read(A &first, B &...second) {
  return read(first) && read(second...);
}
template <typename A>
inline bool write(A first) {
  if (!first) putc('0');
  if (first < 0) putc('-'), first = -first;
  while (first) qu[++qr] = first % 10 + '0', first /= 10;
  while (qr) putc(qu[qr--]);
  return 0;
}
inline bool write(char first) {
  putc(first);
  return 0;
}
inline bool write(const char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
  return 0;
}
inline bool write(char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
  return 0;
}
template <typename A, typename... B>
inline bool write(A first, B... second) {
  return write(first) || write(second...);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::putc;
using io ::read;
using io ::write;
long long a[1005], b[1005], m;
namespace flow {
const long long N = 1000005;
const long long M = 2000005;
long long to[M], lst[M], beg[N], w[M], e = 1, cur[N], q[N], dis[M];
bitset<N> vis;
long long n, s, t;
void init(long long xn, long long xs, long long xt) {
  n = xn;
  s = xs;
  t = xt;
  e = 1;
  for (long long i = 1; i <= n; ++i) beg[i] = 0;
}
void add(long long u, long long v, long long c) {
  to[++e] = v;
  lst[e] = beg[u];
  beg[u] = e;
  w[e] = c;
  to[++e] = u;
  lst[e] = beg[v];
  beg[v] = e;
  w[e] = 0;
}
bool bfs() {
  for (long long i = 1; i <= n; ++i) {
    cur[i] = beg[i];
    dis[i] = n + 1;
  }
  dis[s] = 0;
  long long *l = q, *r = q;
  *(l = r = q) = s;
  while (l <= r) {
    for (long long i = beg[*l]; i; i = lst[i])
      if (w[i] && chkmin(dis[to[i]], dis[*l] + 1)) *(++r) = to[i];
    ++l;
  }
  return dis[t] < n;
}
long long dfs(long long s, long long t, long long fl) {
  if (s == t) return fl;
  for (long long &i = cur[s]; i; i = lst[i])
    if (w[i] && dis[s] + 1 == dis[to[i]]) {
      long long v = dfs(to[i], t, mmin(fl, w[i]));
      if (v) {
        w[i] -= v;
        w[i ^ 1] += v;
        return v;
      }
    }
  return 0;
}
long long calc() {
  long long flow;
  long long ans = 0;
  while (bfs()) {
    while ((flow = dfs(s, t, 0x7fffffff))) ans += flow;
  }
  for (long long i = 1; i <= n; ++i) vis[i] = (dis[i] <= n);
  return ans;
}
}  // namespace flow
long long id[1005];
long long u[1005], v[1005];
long long ans[1005];
long long mn[1005], mx[1005];
long long n, se;
void solve(long long l, long long r) {
  if (l == r) return;
  long long c = 2;
  long long s = 1, t = 2;
  long long mid = (l + r) >> 1;
  for (long long i = 1; i <= n; ++i)
    if (mn[i] == l) {
      id[i] = ++c;
    } else
      id[i] = 0;
  flow::init(c, s, t);
  for (long long i = 1; i <= n; ++i)
    if (id[i]) {
      flow::add(s, id[i], (aabs(b[mid] - a[i])));
      flow::add(id[i], t, (aabs(b[mid + 1] - a[i])));
    }
  for (long long i = 1; i <= se; ++i)
    if (mn[u[i]] == l && mn[v[i]] == l) {
      flow::add(id[u[i]], id[v[i]], inf);
    }
  flow::calc();
  for (long long i = 1; i <= n; ++i)
    if (mn[i] == l) {
      if (flow::vis[id[i]]) {
        mn[i] = mid + 1;
      } else
        mx[i] = mid;
    }
  solve(l, mid);
  solve(mid + 1, r);
}
signed main() {
  read(n, se);
  for (long long i = 1; i <= n; ++i) {
    read(a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;
  for (long long i = 1; i <= se; ++i) read(u[i], v[i]);
  for (long long i = 1; i <= n; ++i) mn[i] = 1, mx[i] = m;
  solve(1, m);
  for (long long i = 1; i <= n; ++i) write(a[mn[i]], i == n ? '\n' : ' ');
  return 0;
}
