#include <bits/stdc++.h>
template <class t>
inline void read(t &s) {
  s = 0;
  register long long f = 1;
  register char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  ;
  s *= f;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0) putchar('-'), x = -x;
  static long long buf[21], top = 0;
  while (x) buf[++top] = x % 10, x /= 10;
  if (!top) buf[++top] = 0;
  while (top) putchar(buf[top--] ^ '0');
}
inline void setIn(std::string s) {
  freopen(s.c_str(), "r", stdin);
  return;
}
inline void setOut(std::string s) {
  freopen(s.c_str(), "w", stdout);
  return;
}
inline void setIO(std::string s = "") {
  setIn(s + ".in");
  setOut(s + ".out");
  return;
}
template <class t>
inline bool ckmin(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
inline bool ckmax(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline long long lowbit(long long x) { return x & (-x); }
const long long MaxN = 2e5 + 50;
struct Node {
  long long ans, Llen, Ls, Rlen, Rs, len;
  inline Node operator+(const Node &nt) const {
    Node res;
    res.len = len + nt.len;
    res.ans = ans + nt.ans;
    res.Llen = Llen, res.Ls = Ls, res.Rlen = nt.Rlen, res.Rs = nt.Rs;
    if (Rs <= nt.Ls) res.ans += Rlen * nt.Llen;
    if (nt.Rlen == nt.len && Rs <= nt.Ls) res.Rlen += Rlen;
    if (Llen == len && Rs <= nt.Ls) res.Llen += nt.Llen;
    return res;
  }
} a[MaxN << 2];
inline void Set(long long x, long long k) { a[x] = (Node){1, 1, k, 1, k, 1}; }
inline void buildtr(long long u, long long l, long long r) {
  if (l == r) {
    long long x;
    read(x);
    Set(u, x);
    return;
  }
  register long long mid = (l + r) >> 1;
  buildtr((u << 1), l, mid), buildtr((u << 1 | 1), mid + 1, r);
  a[u] = a[(u << 1)] + a[(u << 1 | 1)];
}
inline void upd(long long u, long long l, long long r, long long p) {
  if (l == r) {
    long long x;
    read(x);
    Set(u, x);
    return;
  }
  register long long mid = (l + r) >> 1;
  p <= mid ? upd((u << 1), l, mid, p) : upd((u << 1 | 1), mid + 1, r, p);
  a[u] = a[(u << 1)] + a[(u << 1 | 1)];
}
inline Node ask(long long u, long long l, long long r, long long ql,
                long long qr) {
  if (ql <= l && r <= qr) return a[u];
  register long long mid = (l + r) >> 1;
  if (ql > mid) return ask((u << 1 | 1), mid + 1, r, ql, qr);
  if (mid >= qr) return ask((u << 1), l, mid, ql, qr);
  return ask((u << 1), l, mid, ql, qr) + ask((u << 1 | 1), mid + 1, r, ql, qr);
}
signed main(void) {
  long long n, m;
  read(n, m);
  buildtr(1, 1, n);
  register long long opt, x, y;
  while (m--) {
    read(opt, x);
    if (opt == 1)
      upd(1, 1, n, x);
    else
      read(y), write(ask(1, 1, n, x, y).ans), putchar('\n');
  }
  return 0;
}
