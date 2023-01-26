#include <bits/stdc++.h>
const int P = 1e9 + 7;
using namespace std;
template <typename T>
inline void ckmax(T &a, T b) {
  (a < b) && (a = b);
}
template <typename T>
inline void ckmin(T &a, T b) {
  (a > b) && (a = b);
}
inline int mul(int a, int b) { return 1ull * a * b % P; }
inline int add(int a, int b) { return a + b >= P ? a + b - P : a + b; }
inline int sub(int a, int b) { return a - b >= 0 ? a - b : a - b + P; }
inline void mulmod(int &a, int b) { a = mul(a, b); }
inline void addmod(int &a, int b) { ((a += b) >= P) && (a -= P); }
inline void submod(int &a, int b) { ((a -= b) < 0) && (a += P); }
inline int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = 1ll * ans * a % P;
    a = 1ll * a * a % P;
  }
  return ans;
}
inline void fprint(const int &x, char c = ' ') {
  fprintf(stderr, "%d%c", x, c);
}
inline void fprint(const pair<int, int> &x, char c = '\n') {
  fprintf(stderr, "%d %d%c", x.first, x.second, c);
}
inline void fprint(const int *f, const int &n, char c = '\n') {
  for (int i = 1; i <= n; i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline void fprint(const vector<int> &f, char c = '\n') {
  for (int i = 0; i < (int)f.size(); i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline int inv(int a) { return ksm(a, P - 2); }
namespace FastIO {
const int SIZE = 1 << 16;
char buf[SIZE], obuf[SIZE], str[64];
int bi = SIZE, bn = SIZE, opt;
int read(char *s) {
  while (bn) {
    for (; bi < bn && buf[bi] <= ' '; bi++)
      ;
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  int sn = 0;
  while (bn) {
    for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  s[sn] = 0;
  return sn;
}
bool read(int &x) {
  if (x) x = 0;
  int bf = 0, n = read(str);
  if (!n) return 0;
  int i = 0;
  if (str[i] == '-') bf = 1, i = 1;
  for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
  if (bf) x = -x;
  return 1;
}
void write(int x) {
  if (!x)
    obuf[opt++] = '0';
  else {
    if (x < 0) obuf[opt++] = '-', x = -x;
    int sn = 0;
    while (x) str[sn++] = x % 10 + '0', x /= 10;
    for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
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
inline int read() {
  int x = 0;
  FastIO::read(x);
  return x;
}
const int MN = 4e5 + 5;
int n, m, p[MN], a[MN], b[MN];
set<int> s;
struct BIT {
  static const int N = MN;
  int c[N];
  void upd(int x, int v) {
    for (; x <= 2 * n; x += x & -x) addmod(c[x], v);
  }
  void upd(int l, int r, int v) {
    v %= P;
    upd(l, v), upd(r + 1, P - v);
  }
  int qry(int x) {
    int ans = 0;
    for (; x; x -= x & -x) addmod(ans, c[x]);
    return ans;
  }
} tr;
signed main() {
  n = read();
  for (int i = (1); i <= (n); i++) a[i] = read(), b[i] = read(), p[i] = i;
  sort(p + 1, p + 1 + n, [&](int x, int y) { return a[x] < a[y]; });
  s.insert(-((1 << 30) - 1));
  m = read();
  for (int i = (1); i <= (m); i++) {
    s.insert(b[read()]);
  }
  int ans = 0;
  for (int tt = (1); tt <= (n); tt++) {
    int i = p[tt];
    int val = tr.qry(b[i]);
    if (b[i] <= *--s.end()) val++;
    tr.upd(a[i], b[i], val);
    addmod(ans, val);
    s.erase(b[i]);
  }
  cout << ans << endl;
  return 0;
}
