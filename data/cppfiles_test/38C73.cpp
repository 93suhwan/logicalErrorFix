#include <bits/stdc++.h>
const int P = 998244353;
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
const int MN = 1e6 + 5;
vector<int> a[MN], s[MN];
int n, m;
char str[MN];
int getsums(int x, int r, int y, int c) {
  return s[r][c] - s[r][y - 1] - s[x - 1][c] + s[x - 1][y - 1];
}
int getsuma(int x, int r, int y, int c) {
  return a[r][c] - a[r][y - 1] - a[x - 1][c] + a[x - 1][y - 1];
}
void works() {
  n = read(), m = read();
  for (int i = (0); i <= (n + 1); i++) {
    a[i].clear(), s[i].clear();
    a[i].resize(m + 3), s[i].resize(m + 3);
  }
  for (int i = (1); i <= (n); i++) {
    FastIO::read(str + 1);
    for (int j = (1); j <= (m); j++) {
      a[i][j] = str[j] == 'X';
    }
  }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) {
      s[i][j] = a[i][j] && a[i - 1][j + 1];
    }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) {
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  int q = read();
  while (q--) {
    int l = read(), r = read();
    if (getsums(1, n, l, r - 1)) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
}
signed main() {
  int T = 1;
  while (T--) {
    works();
  }
  return 0;
}
