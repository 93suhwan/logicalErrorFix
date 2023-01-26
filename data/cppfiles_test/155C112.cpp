#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <typename T>
inline void read(T& sum) {
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
T gcd(T a, T b) {
  if (!a || !b) return max(a, b);
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
template <typename T>
T C(T m, T n) {
  if (n > m) return 0;
  if (n == 0 || m == 1 || m == n) return 1;
  return C(m - 1, n - 1) + C(m - 1, n);
}
template <typename T>
void exgcd(T a, T b, T& d, T& x, T& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
template <typename T>
T niyuan(T a, T p) {
  T d, x, y;
  exgcd(a, p, d, x, y);
  return d == 1 ? (x + p) % p : -1;
}
template <typename T>
T extgcd(T a, T b, T& x, T& y) {
  if (b) {
    T r = extgcd(b, a % b, y, x);
    y -= x * (a / b);
    return r;
  } else {
    x = 1;
    y = 0;
    return a;
  }
}
template <typename T>
T ax_bmodM(T a, T b, T M) {
  T x, y, r = extgcd(a, M, x, y);
  if (b % r)
    return -1;
  else
    x = (x + M) % M * b / r;
  return x % (M / r);
}
template <typename T>
inline T dmod(const string& s, T mod) {
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
  return ((a % mod) * (b % mod)) % mod;
}
template <typename T>
inline T mod_chu(T a, T b, T p) {
  b = ksm(b, p - 2, p);
  return a * b % p;
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
inline void stgcd(T f[][20], T n) {
  for (int i = 1; i <= n; i++) cin >> f[i][0], f[i + n][0] = f[i][0];
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i + (1 << j) - 1 <= 2 * n; i++) {
      f[i][j] = __gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
}
template <typename T>
inline T qgcd(T f[][20], T z, T y) {
  int x = int(log(y - z + 1) / log(2));
  return __gcd(f[z][x], f[y - (1 << x) + 1][x]);
}
template <typename T>
inline T rotatex(T x, T y, T ang, T ox = 0, T oy = 0) {
  return (x - ox) * cos(ang) - (y - oy) * sin(ang) + ox;
}
template <typename T>
inline T rotatey(T x, T y, T ang, T ox = 0, T oy = 0) {
  return (x - ox) * sin(ang) + (y - oy) * cos(ang) + oy;
}
vector<int> l, y;
char s[200005];
pair<int, int> p[200005];
int a[200005], ans[200005];
bool cmp(int x, int y) { return a[x] < a[y]; }
void solve() {
  l.clear();
  y.clear();
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = make_pair(a[i], i);
  }
  cin >> (s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1')
      y.push_back(i);
    else
      l.push_back(i);
  }
  int xx = 0;
  int long long = l.size();
  int yy = y.size();
  sort(y.begin(), y.end(), cmp);
  sort(l.begin(), l.end(), cmp);
  for (auto& i : l) ans[i] = ++xx;
  for (auto& i : y) ans[i] = ++xx;
  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int _t;
  cin >> _t;
  while (_t--) solve();
  return 0;
}
