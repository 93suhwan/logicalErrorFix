#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
inline int mrand(int k) { return abs((int)mt()) % k; }
template <class num_t>
void modadd(num_t& a, num_t b, num_t p) {
  if ((a += b) >= p) a -= p;
}
template <class num_t>
void modsub(num_t& a, num_t b, num_t p) {
  if ((a -= b) < 0) a += p;
}
template <class num_t>
num_t modmul(num_t a, num_t b, num_t p) {
  num_t r = 0;
  int block = 20;
  num_t base = 1LL << block;
  for (; b; b >>= block) {
    r = (r + a * (b & (base - 1))) % p;
    a = a * base % p;
  }
  return r;
}
template <class num_t>
num_t modpow(num_t n, num_t k, num_t p) {
  if (!n) return 0;
  num_t r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = modmul(r, n, p);
    n = modmul(n, n, p);
  }
  return r;
}
void chemthan() {
  long long mod = (long long)44 * MOD + 1;
  long long base = 79;
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  vector<int> sum;
  vector<long long> f;
  int s = 0;
  long long t = 0;
  vector<long long> g;
  for (int i = (0); i < (n); ++i) {
    addmod(s, a[i], mod);
    sum.push_back(s);
    long long e = modpow<long long>(base, a[i], mod);
    modadd(t, e, mod);
    f.push_back(t);
    g.push_back(e);
  }
  vector<pair<int, int> > vals;
  for (int i = (0); i < (n); ++i) vals.push_back({a[i], i});
  sort((vals).begin(), (vals).end());
  auto find = [&](int x) {
    int k = lower_bound((vals).begin(), (vals).end(), make_pair(x, 0)) -
            vals.begin();
    if (k < int((vals).size()) && vals[k].first == x) {
      return vals[k].second;
    }
    return -1;
  };
  while (q--) {
    int l, r, d;
    cin >> l >> r >> d;
    l--, r--;
    int s = sum[r];
    if (l) submod(s, sum[l - 1]);
    int tmp = (long long)(r - l) * (r - l + 1) / 2 % MOD;
    tmp = mult(d, tmp);
    submod(s, tmp);
    s = mult(s, inv(r - l + 1));
    int ix = find(s);
    if (ix == -1) {
      cout << "No\n";
      continue;
    }
    long long expected = f[r];
    if (l) modsub<long long>(expected, f[l - 1], mod);
    long long coef = g[ix];
    long long a = modpow<long long>(base, d, mod);
    long long b = modpow<long long>(a, r - l + 1, mod);
    long long c = modmul(b - 1, modpow<long long>(a - 1, mod - 2, mod), mod);
    long long actual = modmul(coef, c, mod);
    if (expected == actual) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
