#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 50;
template <typename A, typename B>
istream& operator>>(istream& o, pair<A, B>& a) {
  return o >> a.first >> a.second;
}
template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> a) {
  return o << '(' << a.first << ", " << a.second << ')';
}
namespace io {
const long long SIZE = 1e7 + 10;
char inbuff[SIZE];
char *l, *r;
inline void init() {
  l = inbuff;
  r = inbuff + fread(inbuff, 1, SIZE, stdin);
}
inline char gc() {
  if (l == r) init();
  return (l != r) ? *(l++) : EOF;
}
void R(long long& x) {
  bool neg = 0;
  x = 0;
  char ch = gc();
  while (!isdigit(ch)) {
    if (ch == '-') neg = 1;
    ch = gc();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
  if (neg) x = -x;
}
}  // namespace io
using io::R;
void solve() {
  long long n, q, sz = 300, tot = 0;
  R(n), R(q);
  vector<long long> a(n), id(n), jp(n), r(n);
  for (long long& o : a) R(o), o--;
  for (long long i = 0; i <= n - 1; i++) {
    if (!id[a[i]]) {
      tot++;
      long long t = a[i];
      while (!id[t]) {
        id[t] = tot;
        r[a[t]] = t;
        t = a[t];
      }
    }
  }
  for (long long i = 0; i <= n - 1; i++) {
    long long t = i;
    for (long long j = 1; j <= sz; j++) t = a[t];
    jp[i] = t;
  }
  while (q--) {
    long long o, x, y;
    R(o), R(x), R(y);
    x--;
    if (o == 1) {
      y--;
      long long tx = x, gpx = jp[y], ty = y, gpy = jp[x];
      r[a[x]] = y;
      r[a[y]] = x;
      swap(a[x], a[y]);
      for (long long i = 1; i <= sz; i++) {
        tx = r[tx];
        ty = r[ty];
        gpx = r[gpx];
        gpy = r[gpy];
        jp[tx] = gpx;
        jp[ty] = gpy;
      }
    } else {
      long long t = x;
      for (long long i = 1; i <= y / sz; i++) t = jp[t];
      for (long long i = 1; i <= y - y / sz * sz; i++) t = a[t];
      printf("%lld\n", t + 1);
    }
  }
}
void input() {}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  ;
  long long tt = 1;
  while (tt--) {
    input();
    solve();
  }
}
