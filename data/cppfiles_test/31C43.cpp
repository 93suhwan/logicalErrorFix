#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1048579;
const long long SQRTN = 1003;
const long long LOGN = 22;
const double PI = acos(-1);
const long long INF = 1e16;
const long long MOD = 1000000007;
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
const long long FACSZ = 1;
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long testcase = 1; testcase < t + 1; testcase++) {
    solvethetestcase();
  }
}
long long n, k;
long long p2;
struct node {
  long long mn, mx, val, ln, lft, rgt;
  node() {
    mn = INF;
    mx = -INF;
    val = INF;
    lft = -1;
    rgt = -1;
    ln = 1;
  }
};
node seg[MAXN];
long long ans[MAXN];
void calc(long long i) {
  long long l = seg[i].ln / 2;
  seg[i].mn = min(seg[seg[i].lft].mn, seg[seg[i].rgt].mn + l);
  seg[i].mx = max(seg[seg[i].lft].mx, seg[seg[i].rgt].mx + l);
  seg[i].val = min({seg[2 * i].val, seg[2 * i + 1].val,
                    l + seg[seg[i].rgt].mn - seg[seg[i].lft].mx});
}
void solvethetestcase() {
  cin >> n >> k;
  p2 = (1 << k);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    seg[x + p2].mn = 0;
    seg[x + p2].mx = 0;
  }
  for (long long i = p2 - 1; i >= 1; i--) {
    seg[i].lft = 2 * i;
    seg[i].rgt = 2 * i + 1;
    seg[i].ln = seg[2 * i].ln * 2;
    calc(i);
  }
  ans[0] = seg[1].val;
  long long cur = 0;
  for (long long i = 1; i < (1 << k); i++) {
    long long hp = 0;
    for (long long j = 0; j < k; j++) {
      if (i % (1 << j) == 0)
        hp = j;
      else
        break;
    }
    cur ^= (1 << (k - 1 - hp));
    for (long long j = (1 << hp); j < (1 << (hp + 1)); j++) {
      swap(seg[j].lft, seg[j].rgt);
      calc(j);
    }
    for (long long j = (1 << hp) - 1; j >= 1; j--) calc(j);
    ans[cur] = seg[1].val;
  }
  for (long long i = 0; i < (1 << k); i++) cout << ans[i] << " ";
  cout << "\n";
}
