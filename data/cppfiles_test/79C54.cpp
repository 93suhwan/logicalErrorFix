#include <bits/stdc++.h>
template <class T>
inline T max(const T &x, const T &y) {
  return x > y ? x : y;
}
template <class T>
inline T min(const T &x, const T &y) {
  return x < y ? x : y;
}
template <class T>
inline bool chkmax(T &x, const T &y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool chkmin(T &x, const T &y) {
  return x > y ? x = y, true : false;
}
inline long long read() {
  register long long x = 0, v = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') v = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * v;
}
const long long MAXN = 3e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long n, ans;
long long a[MAXN | 1], b[MAXN | 1], dp[MAXN | 1], lst[MAXN | 1];
struct SGT {
  long long minv[MAXN << 2 | 1], lazy[MAXN << 2 | 1], posv[MAXN << 2 | 1],
      tag[MAXN << 2 | 1];
  SGT() {
    memset(minv, 0x3f, sizeof(minv));
    memset(lazy, 0x3f, sizeof(lazy));
  }
  void push_down(long long o) {
    if (lazy[o] == INF) return;
    if (chkmin(minv[(o << 1)], lazy[o])) posv[(o << 1)] = tag[o];
    if (chkmin(minv[(o << 1 | 1)], lazy[o])) posv[(o << 1 | 1)] = tag[o];
    if (chkmin(lazy[(o << 1)], lazy[o])) tag[(o << 1)] = tag[o];
    if (chkmin(lazy[(o << 1 | 1)], lazy[o])) tag[(o << 1 | 1)] = tag[o];
    lazy[o] = INF;
  }
  void push_up(long long o) {
    minv[o] = minv[(o << 1)];
    posv[o] = posv[(o << 1)];
    if (chkmin(minv[o], minv[(o << 1 | 1)])) posv[o] = posv[(o << 1 | 1)];
  }
  void build(long long o = 1, long long l = 0, long long r = n) {
    minv[o] = lazy[o] = INF;
    if (l == r) {
      posv[o] = l;
      return;
    }
    long long mid = (l + r) >> 1;
    build((o << 1), l, mid);
    build((o << 1 | 1), mid + 1, r);
    push_up(o);
  }
  void update(long long ql, long long qr, long long val, long long pos,
              long long o = 1, long long l = 0, long long r = n) {
    if (ql > qr) return;
    if (ql <= l && r <= qr) {
      if (chkmin(minv[o], val)) posv[o] = pos;
      if (chkmin(lazy[o], val)) tag[o] = pos;
      return;
    }
    long long mid = (l + r) >> 1;
    push_down(o);
    if (ql <= mid) update(ql, qr, val, pos, (o << 1), l, mid);
    if (mid < qr) update(ql, qr, val, pos, (o << 1 | 1), mid + 1, r);
    push_up(o);
  }
  std::pair<long long, long long> query(long long pos, long long o = 1,
                                        long long l = 0, long long r = n) {
    if (l == r) return std::make_pair(minv[o], posv[o]);
    long long mid = (l + r) >> 1;
    push_down(o);
    if (pos <= mid)
      return query(pos, (o << 1), l, mid);
    else
      return query(pos, (o << 1 | 1), mid + 1, r);
  }
} T;
signed main() {
  n = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  for (long long i = 1; i <= n; ++i) b[i] = read();
  dp[n] = 0;
  T.build();
  T.update(n, n, 0, 0);
  for (long long i = n; i >= 1; --i) {
    std::pair<long long, long long> tmp = T.query(i);
    long long nowx = i + b[i], nowv = tmp.first + 1;
    T.update(nowx - a[nowx], nowx - 1, nowv, i);
  }
  std::pair<long long, long long> now = T.query(0);
  if (now.first == INF) return puts("-1"), 0;
  printf("%lld\n", now.first);
  static std::vector<long long> ans;
  for (long long now = 0; now != n; now = T.query(now).second)
    ans.push_back(now);
  std::reverse(ans.begin(), ans.end());
  for (long long i : ans) printf("%lld ", i);
  return 0;
}
