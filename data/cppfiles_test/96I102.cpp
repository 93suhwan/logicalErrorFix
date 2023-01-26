#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
const int maxn = 2e5 + 100;
const int mod = 998244353;
const int N = 100010;
const int INF = 0x3f3f3f3f;
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
T gcd(T a, T b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
inline char nc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <typename T>
inline void read(T &sum) {
  char ch = nc();
  T tf = 0;
  sum = 0;
  while ((ch < '0' || ch > '9') && (ch != '-')) ch = nc();
  tf = ((ch == '-') && (ch = nc()));
  while (ch >= '0' && ch <= '9') sum = sum * 10 + (ch - 48), ch = nc();
  (tf) && (sum = -sum);
}
template <typename T>
inline void write(T x) {
  if (x == 0) {
    putchar('0');
    return;
  }
  char F[200];
  T tmp = x > 0 ? x : -x;
  if (x < 0) putchar('-');
  T cnt = 0;
  while (tmp > 0) {
    F[cnt++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (cnt > 0) putchar(F[--cnt]);
}
template <typename T>
inline T ra(T z, T y) {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<T>(z, y)(rng);
}
template <typename T>
T niyuan(T a, T b, T &x, T &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  T d = niyuan(b, a % b, x, y);
  T t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
template <typename T>
T ax_bmodn(T a, T b, T n, T &g, T &x, T &y) {
  if (!n) {
    g = a, x = 1, y = 0;
  } else {
    ax___bmodn(n, a % n, g, y, x);
    y -= x * (a / n);
  }
  return x *= (b / g);
}
template <typename T>
inline T dmod(const string &s, T mod) {
  T len = s.size();
  T ans = 0;
  for (T i = 0; i < len; i++)
    ans = (int)(((long long)ans * 10 + s[i] - '0') % mod);
  return ans;
}
template <typename T>
inline T ksc(T a, T b, T mod) {
  T ans = 0;
  while (b > 0) {
    if (b & 1) ans = (ans + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return ans;
}
template <typename T>
inline T ksm(T x, T n, T mod) {
  T ans = 1;
  while (n > 0) {
    if (n & 1) ans = ans * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ans;
}
template <typename T>
inline T mod_jia(T a, T b, T mod) {
  return (a % mod + b % mod) % mod;
}
template <typename T>
inline T mod_jian(T a, T b, T mod) {
  return (a % mod + mod - b % mod) % mod;
}
template <typename T>
inline T mod_cheng(T a, T b, T mod) {
  return (a % mod * b % mod) % mod;
}
template <typename T>
inline T C(T n, T m, T mod) {
  if (m > n) return 0;
  T ans = 1;
  for (T i = 1; i <= m; i++) {
    T a = (n + i - m) % mod;
    T b = i % mod;
    ans = ans * (a * ksm(b, mod - 2, mod) % mod) % mod;
  }
  return ans;
}
template <typename T>
inline void rmqmin(T f[][20], T n) {
  for (int i = 1; i <= n; i++) cin >> f[i][0];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++)
      if (i + (1 << j) - 1 <= n)
        f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}
template <typename T>
inline T zymin(T f[][20], T z, T y) {
  int x = int(log(y - z + 1) / log(2));
  return min(f[z][x], f[y - (1 << x) + 1][x]);
}
template <typename T>
inline void rmqmax(T f[][20], T n) {
  for (int i = 1; i <= n; i++) cin >> f[i][0];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++)
      if (i + (1 << j) - 1 <= n)
        f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}
template <typename T>
inline T zymax(T f[][20], T z, T y) {
  int x = int(log(y - z + 1) / log(2));
  return max(f[z][x], f[y - (1 << x) + 1][x]);
}
template <typename T>
inline T rotatex(T x, T y, T ang, T ox = 0, T oy = 0) {
  return (x - ox) * cos(ang) - (y - oy) * sin(ang) + ox;
}
template <typename T>
inline T rotatey(T x, T y, T ang, T ox = 0, T oy = 0) {
  return (x - ox) * sin(ang) + (y - oy) * cos(ang) + oy;
}
long long qpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    y = y / 2;
    x = x * x % mod;
  }
  return ans;
}
inline int read() {
  int X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
int q, ans, d, ok, id, num, num1, num2, n, m, sum, cnk, maxx,
    minn = INF, xx, yy, u, l, r, pre, op, k, z, x, y, temp, sum1, sum2, A, B,
    cnt, ask, tt, nums, len, ok1, ok2, mid, flag, now;
int a[200010], bit[200010];
set<int> s;
void add(int x, int y) {
  for (; x < maxn; x += (x & -x)) bit[x] += y;
}
int summ(int x) {
  int ret = 0;
  for (; x; x -= (x & -x)) ret += bit[x];
  return ret;
}
void del(int x) {
  auto it = s.find(x);
  add(x, -((x - *prev(it)) * (x - *prev(it) + 1) / 2));
  add(*next(it), -((*next(it) - x) * (*next(it) - x + 1) / 2));
  add(*next(it), ((*next(it) - *prev(it)) * (*next(it) - *prev(it) + 1) / 2));
  s.erase(it);
}
void ins(int x) {
  s.insert(x);
  auto it = s.find(x);
  add(x, ((x - *prev(it)) * (x - *prev(it) + 1) / 2));
  add(*next(it), ((*next(it) - x) * (*next(it) - x + 1) / 2));
  add(*next(it), -((*next(it) - *prev(it)) * (*next(it) - *prev(it) + 1) / 2));
}
void solve() {
  n = read(), q = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  int last = 0;
  s.insert(0);
  a[n + 2] = -1;
  for (long long i = 1; i <= n + 1; i++) {
    if (a[i] > a[i + 1]) {
      add(i, ((i - last) * (i - last + 1) / 2));
      s.insert(i);
      last = i;
    }
  }
  while (q--) {
    ask = read(), x = read(), y = read();
    if (ask == 1) {
      if (a[x - 1] > a[x]) del(x - 1);
      if (a[x] > a[x + 1]) del(x);
      a[x] = y;
      if (a[x - 1] > a[x]) ins(x - 1);
      if (a[x] > a[x + 1]) ins(x);
    } else {
      auto it = s.lower_bound(x);
      if (*it >= y) {
        cout << ((y - x + 1) * (y - x + 1 + 1) / 2) << "\n";
        continue;
      }
      int ans = summ(y) - summ(*it);
      auto it2 = s.upper_bound(y);
      ans += ((y - *prev(it2)) * (y - *prev(it2) + 1) / 2);
      ans += ((*it - x + 1) * (*it - x + 1 + 1) / 2);
      cout << ans << "\n";
    }
  }
  return;
}
signed main() {
  solve();
  return 0;
}
