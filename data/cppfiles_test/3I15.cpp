#include <bits/stdc++.h>
const long long P = 1e9 + 7;
using namespace std;
template <typename T>
inline void ckmax(T &a, T b) {
  (a < b) && (a = b);
}
template <typename T>
inline void ckmin(T &a, T b) {
  (a > b) && (a = b);
}
inline long long mul(long long a, long long b) { return 1ull * a * b % P; }
inline long long add(long long a, long long b) {
  return a + b >= P ? a + b - P : a + b;
}
inline long long sub(long long a, long long b) {
  return a - b >= 0 ? a - b : a - b + P;
}
inline void mulmod(long long &a, long long b) { a = mul(a, b); }
inline void addmod(long long &a, long long b) { ((a += b) >= P) && (a -= P); }
inline void submod(long long &a, long long b) { ((a -= b) < 0) && (a += P); }
inline long long ksm(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = 1ll * ans * a % P;
    a = 1ll * a * a % P;
  }
  return ans;
}
inline void fprint(const long long &x, char c = ' ') {
  fprintf(stderr, "%d%c", x, c);
}
inline void fprint(const pair<long long, long long> &x, char c = '\n') {
  fprintf(stderr, "%d %d%c", x.first, x.second, c);
}
inline void fprint(const long long *f, const long long &n, char c = '\n') {
  for (long long i = 1; i <= n; i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline void fprint(const vector<long long> &f, char c = '\n') {
  for (long long i = 0; i < (long long)f.size(); i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline long long inv(long long a) { return ksm(a, P - 2); }
namespace FastIO {
const long long SIZE = 1 << 16;
char buf[SIZE], obuf[SIZE], str[64];
long long bi = SIZE, bn = SIZE, opt;
long long read(char *s) {
  while (bn) {
    for (; bi < bn && buf[bi] <= ' '; bi++)
      ;
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  long long sn = 0;
  while (bn) {
    for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  s[sn] = 0;
  return sn;
}
bool read(long long &x) {
  if (x) x = 0;
  long long bf = 0, n = read(str);
  if (!n) return 0;
  long long i = 0;
  if (str[i] == '-') bf = 1, i = 1;
  for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
  if (bf) x = -x;
  return 1;
}
void write(long long x) {
  if (!x)
    obuf[opt++] = '0';
  else {
    if (x < 0) obuf[opt++] = '-', x = -x;
    long long sn = 0;
    while (x) str[sn++] = x % 10 + '0', x /= 10;
    for (long long i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
  }
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void write(char x) {
  obuf[opt++] = x;
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void Fflush() {
  if (opt) fwrite(obuf, 1, opt, stdout);
  opt = 0;
}
};  // namespace FastIO
inline long long read() {
  long long x;
  FastIO::read(x);
  return x;
}
const long long MN = 2e5 + 5;
long long n, a[MN], b[MN], m, x, p[MN], q[MN], T = 2e5 + 1;
long long s[MN], top, mx[MN];
void solve(long long *a, long long n, long long *ans) {
  for (long long i = (1); i <= (n); i++) ans[i] = T;
  top = 0;
  reverse(a + 1, a + 1 + n);
  for (long long i = (1); i <= (n); i++) {
    long long nmx = a[i];
    while (top && a[s[top]] >= a[i]) {
      ckmax(nmx, mx[top]);
      top--;
    }
    if (top) ckmin(ans[n - i + 1], nmx);
    mx[++top] = nmx, s[top] = i;
  }
  top = 0;
  reverse(a + 1, a + 1 + n);
  for (long long i = (1); i <= (n); i++) {
    long long nmx = a[i];
    while (top && a[s[top]] > a[i]) {
      ckmax(nmx, mx[top]);
      top--;
    }
    if (top) ckmin(ans[i], nmx);
    mx[++top] = nmx, s[top] = i;
  }
}
pair<long long, long long> A[MN], B[MN];
struct BIT {
  static const long long N = MN;
  long long c[N];
  void upd(long long x, long long v) {
    x++;
    for (; x <= T + 1; x += x & -x) c[x] += v;
  }
  long long qry(long long x) {
    x++;
    long long ans = 0;
    for (; x; x -= x & -x) ans += c[x];
    return ans;
  }
} tr;
bool cmp(pair<long long, long long> x, pair<long long, long long> y) {
  if (y.second != x.second) return x.second < y.second;
  return x.first < y.first;
}
void works() {
  n = read(), m = read(), x = read();
  for (long long i = (1); i <= (n); i++) a[i] = read();
  for (long long i = (1); i <= (m); i++) b[i] = read();
  solve(a, n, p);
  solve(b, m, q);
  for (long long i = (1); i <= (n); i++) A[i] = make_pair(a[i], p[i]);
  for (long long i = (1); i <= (m); i++) B[i] = make_pair(b[i], q[i]);
  sort(A + 1, A + 1 + n);
  sort(B + 1, B + 1 + m, cmp);
  long long ans = 0;
  long long now = 0;
  for (long long i = (1); i <= (m); i++) tr.upd(B[i].first, 1);
  for (long long i = (1); i <= (n); i++) {
    if (A[i].first > x) continue;
    while (now <= m && B[now].second <= x - A[i].first) {
      tr.upd(B[now].first, -1);
      now++;
    }
    ans += tr.qry(x - A[i].first) - tr.qry(max(x - A[i].second, 0ll));
  }
  cout << ans << endl;
}
signed main() {
  long long T = 1;
  while (T--) {
    works();
  }
  return FastIO::Fflush(), 0;
}
