#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T &x, T y) {
  x = x < y ? y : x;
  return;
}
template <typename T>
inline void ckmin(T &x, T y) {
  x = x < y ? x : y;
  return;
}
inline long long read() {
  long long res = 0, f = 1;
  char k;
  while (!isdigit(k = getchar()))
    if (k == '-') f = -1;
  while (isdigit(k)) res = res * 10 + k - '0', k = getchar();
  return res * f;
}
namespace Output {
char OPUT[100];
inline void print(long long x) {
  if (!x) return putchar('0'), putchar('\n'), void();
  if (x < 0) putchar('-'), x = -x;
  long long cnt = 0;
  while (x) OPUT[++cnt] = x % 10, x /= 10;
  for (register long long i = cnt; i >= 1; --i) putchar(OPUT[i] + '0');
  putchar('\n');
  return;
}
}  // namespace Output
using namespace Output;
inline long long gcd(long long x, long long y) {
  return (!y) ? x : gcd(y, x % y);
}
inline long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
const long long mod = 998244353;
inline long long add(long long x, long long y, long long Mod = mod) {
  return x + y >= Mod ? x + y - Mod : x + y;
}
inline long long del(long long x, long long y, long long Mod = mod) {
  return x - y < 0 ? x - y + Mod : x - y;
}
inline long long mul(long long x, long long y, long long Mod = mod) {
  return x * y - x * y / Mod * Mod;
}
inline void ckadd(long long &x, long long y, long long Mod = mod) {
  x = x + y >= Mod ? x + y - Mod : x + y;
}
inline void ckdel(long long &x, long long y, long long Mod = mod) {
  x = x - y < 0 ? x - y + Mod : x - y;
}
inline void ckmul(long long &x, long long y, long long Mod = mod) {
  x = x * y - x * y / Mod * Mod;
}
inline long long ksm(long long x, long long y, long long Mod = mod) {
  long long res = 1;
  for (; y; y >>= 1, ckmul(x, x, Mod))
    if (y & 1) ckmul(res, x, Mod);
  return res;
}
inline void approx(long long val, long long Mod = mod, long long lim = 1e5) {
  long long x = val, y = Mod, a = 1, b = 0;
  while (x > lim) {
    swap(x, y);
    swap(a, b);
    a -= x / y * b;
    x %= y;
  }
  cout << x << "/" << a << endl;
  return;
}
const double pi = acos(-1);
struct Complex {
  double x, y;
  Complex() {}
  Complex(double xx, double yy) {
    x = xx;
    y = yy;
    return;
  }
  Complex operator+(const Complex &a) const {
    return Complex(x + a.x, y + a.y);
  }
  Complex operator-(const Complex &a) const {
    return Complex(x - a.x, y - a.y);
  }
  Complex operator*(const Complex &a) const {
    return Complex(x * a.x - y * a.y, x * a.y + y * a.x);
  }
};
inline pair<Complex, Complex> square_root(Complex a) {
  double len = sqrt(a.x * a.x + a.y * a.y);
  len = sqrt(len);
  double ang = atan2(a.y, a.x), a1 = ang / 2 + pi, a2 = ang / 2;
  if (a2 < 0) a2 += 2 * pi;
  return make_pair(Complex(cos(a1) * len, sin(a1) * len),
                   Complex(cos(a2) * len, sin(a2) * len));
}
inline double cross(Complex a, Complex b) { return a.x * b.y - a.y * b.x; }
struct fractor {
  long long x, y;
  fractor() {}
  fractor(long long xx, long long yy) {
    x = xx;
    y = yy;
    return;
  }
  fractor operator+(const fractor &a) const {
    long long mu = lcm(y, a.y), zi = x * (mu / y) + a.x * (mu / a.y);
    long long g = gcd(mu, zi);
    return fractor(zi / g, mu / g);
  }
  fractor operator*(const fractor &a) const {
    long long gg = gcd(y, a.x) * gcd(x, a.y);
    return fractor(x * a.x / gg, y * a.y / gg);
  }
  bool operator<(const fractor &a) const {
    long long da = x / y, db = a.x / a.y;
    if (da ^ db) return da < db;
    fractor t1 = fractor(x - y * da, y), t2 = fractor(a.x - a.y * db, a.y);
    return t1.x * t2.y < t2.x * t1.y;
  }
};
const long long N = 1e5 + 10;
long long n, ans, a[N], dp[N];
char s1[100010], s2[100010];
inline long long random(long long x) { return 1ll * rand() * rand() % x + 1; }
inline long long random(long long l, long long r) {
  return 1ll * rand() * rand() % (r - l + 1) + l;
}
signed main() {
  srand((unsigned)time(0));
  long long T = read();
  while (T--) {
    n = read(), ans = 0;
    scanf("%s%s", s1 + 1, s2 + 1);
    for (register long long i = 1; i <= n; ++i)
      a[i] = s1[i] - '0' + s2[i] - '0', dp[i] = 0;
    if (n == 1) {
      if (a[1] == 0)
        print(1);
      else if (a[1] == 1)
        print(2);
      else
        print(0);
      continue;
    }
    ans = (a[1] == 1) * 2;
    for (register long long i = 2; i <= n; ++i) {
      if (a[i] == 2) {
        if (a[i - 1] == 0 && dp[i - 1] == 0) dp[i] = 1, ans += 2;
      } else if (a[i] == 1) {
        ans += 2;
        if (a[i - 1] == 0 && !dp[i - 1]) ans += 1;
      } else {
        if (a[i - 1] == 2 && dp[i - 1] == 0)
          dp[i] = 1, ans += 2;
        else if (a[i - 1] == 0)
          ans += 1;
      }
    }
    if (!dp[n] && a[n] == 0) ++ans;
    print(ans);
  }
  return 0;
}
