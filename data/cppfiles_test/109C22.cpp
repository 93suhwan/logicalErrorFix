#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 300005;
const long long SQRTN = 1003;
const long long LOGN = 22;
const double PI = acos(-1);
const long long INF = 1e16;
const long long MOD = 998244353;
const long long FMOD = 998244353;
const double eps = 1e-9;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
long long add(long long a, long long b, long long c = MOD) {
  long long res = a + b;
  return (res >= c ? res - c : res);
}
long long mod_neg(long long a, long long b, long long c = MOD) {
  long long res;
  if (abs(a - b) < c)
    res = a - b;
  else
    res = (a - b) % c;
  return (res < 0 ? res + c : res);
}
long long mul(long long a, long long b, long long c = MOD) {
  long long res = (long long)a * b;
  return (res >= c ? res % c : res);
}
long long muln(long long a, long long b, long long c = MOD) {
  long long res = (long long)a * b;
  return ((res % c) + c) % c;
}
long long mulmod(long long a, long long b, long long m = MOD) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T expo(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T power(T e, T n, T m = MOD) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mul(x, p, m);
    p = mul(p, p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T extended_euclid(T a, T b, T& x, T& y) {
  T xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    T q = a / b, t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
template <typename T>
T mod_inverse(T a, T n = MOD) {
  T x, y, z = 0;
  T d = extended_euclid(a, n, x, y);
  return (d > 1 ? -1 : mod_neg(x, z, n));
}
const long long FACSZ = MAXN;
long long fact[FACSZ], ifact[FACSZ];
void precom(long long c = MOD) {
  fact[0] = 1;
  for (long long i = 1; i < FACSZ; i++) fact[i] = mul(fact[i - 1], i, c);
  ifact[FACSZ - 1] = mod_inverse(fact[FACSZ - 1], c);
  for (long long i = FACSZ - 1 - 1; i >= 0; i--) {
    ifact[i] = mul(i + 1, ifact[i + 1], c);
  }
}
long long ncr(long long n, long long r, long long c = MOD) {
  if (r > n) return 0;
  return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}
void solvethetestcase();
signed main() {
  precom();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long testcase = 1; testcase < t + 1; testcase++) {
    solvethetestcase();
  }
}
long long n;
string a[MAXN];
void solvethetestcase() {
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long c1 = 0, c2 = 1, c3 = 1;
  for (long long i = 0; i < n; i++) {
    if (!(a[i][0] == '?' or a[i][0] == 'B')) c2 = 0;
    if (!(a[i][1] == '?' or a[i][1] == 'W')) c2 = 0;
  }
  for (long long i = 0; i < n; i++) {
    if (!(a[i][0] == '?' or a[i][0] == 'W')) c3 = 0;
    if (!(a[i][1] == '?' or a[i][1] == 'B')) c3 = 0;
  }
  long long open = 0, fb = 0, fc = 0, ob = 0, oc = 0, mix = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i][0] == '?' and a[i][1] == '?')
      open++;
    else if (a[i][0] == a[i][1]) {
      if (a[i][0] == 'B')
        fb++;
      else
        fc++;
    } else if (a[i][0] != '?' and a[i][1] != '?')
      mix++;
    else if (a[i][0] == 'B' or a[i][1] == 'B')
      ob++;
    else
      oc++;
  }
  long long ans = (c2 + c3);
  long long x = 0, opx = 0;
  opx += 2 * open;
  x -= open;
  x += fb;
  x -= fc;
  opx += ob;
  opx += oc;
  x -= oc;
  if (x <= 0) ans = (ans + ncr(opx, -x)) % FMOD;
  if (fb == 0 and fc == 0) {
    ans -= power(2LL, open);
    ans %= FMOD;
    ans += FMOD;
    ans %= FMOD;
  }
  cout << ans << "\n";
}
