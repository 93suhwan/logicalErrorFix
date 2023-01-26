#include <bits/stdc++.h>
using namespace std;
namespace nqio {
const unsigned R = 4e5, W = 4e5;
char *a, *b, i[R], o[W], *c = o, *d = o + W, h[40], *p = h, y;
bool s;
struct q {
  void r(char& x) {
    x = a == b && (b = (a = i) + fread(i, 1, R, stdin), a == b) ? -1 : *a++;
  }
  void f() {
    fwrite(o, 1, c - o, stdout);
    c = o;
  }
  ~q() { f(); }
  void w(char x) {
    *c = x;
    if (++c == d) f();
  }
  q& operator>>(char& x) {
    do r(x);
    while (x <= 32);
    return *this;
  }
  q& operator>>(char* x) {
    do r(*x);
    while (*x <= 32);
    while (*x > 32) r(*++x);
    *x = 0;
    return *this;
  }
  template <typename t>
  q& operator>>(t& x) {
    for (r(y), s = 0; !isdigit(y); r(y)) s |= y == 45;
    if (s)
      for (x = 0; isdigit(y); r(y)) x = x * 10 - (y ^ 48);
    else
      for (x = 0; isdigit(y); r(y)) x = x * 10 + (y ^ 48);
    return *this;
  }
  q& operator<<(char x) {
    w(x);
    return *this;
  }
  q& operator<<(char* x) {
    while (*x) w(*x++);
    return *this;
  }
  q& operator<<(const char* x) {
    while (*x) w(*x++);
    return *this;
  }
  template <typename t>
  q& operator<<(t x) {
    if (!x)
      w(48);
    else if (x < 0)
      for (w(45); x; x /= 10) *p++ = 48 | -(x % 10);
    else
      for (; x; x /= 10) *p++ = 48 | x % 10;
    while (p != h) w(*--p);
    return *this;
  }
} qio;
}  // namespace nqio
using nqio::qio;
const long long mod = 998244353;
template <typename T>
inline void chkadd(T& x, T y) {
  x = x + y >= mod ? x + y - mod : x + y;
}
template <typename T>
inline void chkadd(T& x, T y, T z) {
  x = y + z >= mod ? y + z - mod : y + z;
}
template <typename T>
inline void chkmns(T& x, T y) {
  x = x - y < 0 ? x - y + mod : x - y;
}
template <typename T>
inline void chkmns(T& x, T y, T z) {
  x = y - z < 0 ? y - z + mod : y - z;
}
template <typename T>
inline void chkmax(T& x, T y) {
  x = x < y ? y : x;
}
template <typename T>
inline void chkmax(T& x, T y, T z) {
  x = y > z ? y : z;
}
template <typename T>
inline void chkmin(T& x, T y) {
  x = x < y ? x : y;
}
template <typename T>
inline void chkmin(T& x, T y, T z) {
  x = y < z ? y : z;
}
long long qpow(long long x, long long p) {
  long long base = x, res = 1;
  while (p) {
    if (p & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    p >>= 1;
  }
  return res;
}
mt19937 mtrnd(std::chrono::system_clock::now().time_since_epoch().count());
const int N = 405;
char S[N][N];
int arr[N][N];
int pre[N][N];
int f[3][N][N];
int n, m;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> (S[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) arr[i][j] = S[i][j] - '0';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) pre[i][j] = pre[i][j - 1] + arr[i][j];
  for (int i = 0; i <= 2; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 1; k <= m; k++) f[i][j][k] = (int)1e9;
  int ans = 1e9;
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++)
      for (int k = 1; k <= m; k++) {
        if (k - j < 3) continue;
        auto calc1 = [&](int i, int j, int k) {
          return pre[i][k - 1] - pre[i][j] + (1 - arr[i][j]) + (1 - arr[i][k]);
        };
        auto calc2 = [&]() {
          if (i + 3 > n) return (int)1e9;
          int ret = 0;
          for (int t = 0; t <= 2; t++) ret += calc1(i + t, j, k);
          ret += (k - j - 1) - (pre[i + 3][k - 1] - pre[i + 3][j]);
          return ret;
        };
        auto calcans = [&](int i, int j, int k) {
          ans = min(ans, (k - j - 1) - (pre[i][k - 1] - pre[i][j]) +
                             f[i + 1 & 1][j][k]);
        };
        f[i & 1][j][k] = min(calc1(i, j, k) + f[i + 1 & 1][j][k], calc2());
        if (i > 1) calcans(i - 1, j, k);
      }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  cerr << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
