#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long root = 15311432;
const long long root_1 = 469870224;
const long long root_pw = 1 << 23;
template <class T>
T eea(T a, T b, T& x, T& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  T x1, y1;
  T g = eea(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
long long inverse(long long n) {
  long long x, y;
  eea(n, mod, x, y);
  x %= mod;
  if (x < 0) x += mod;
  return x;
}
void fft(vector<long long>& a, bool invert) {
  long long n = a.size();
  for (long long i = 1, j = 0; i < n; i++) {
    long long bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (long long len = 2; len <= n; len <<= 1) {
    long long wlen = invert ? root_1 : root;
    for (long long i = len; i < root_pw; i <<= 1)
      wlen = 1LL * wlen * wlen % mod;
    for (long long i = 0; i < n; i += len) {
      long long w = 1;
      for (long long j = 0; j < len / 2; j++) {
        long long u = a[i + j],
                  v = (long long)(1LL * a[i + j + len / 2] * w % mod);
        a[i + j] = u + v < mod ? u + v : u + v - mod;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
        w = 1LL * w * wlen % mod;
      }
    }
  }
  if (invert) {
    long long n_1 = inverse(n);
    for (long long& x : a) x = 1LL * x * n_1 % mod;
  }
}
const long long maxn = 250050;
vector<long long> e(maxn);
void f(long long& x) {
  if (abs(x) >= mod) x %= mod;
  if (x < 0) x += mod;
}
long long g(long long x) {
  f(x);
  return x;
}
vector<long long> multiply(vector<long long> a, vector<long long> b) {
  long long n = 1;
  long long na = a.size(), nb = b.size();
  while (n < na + nb) n <<= 1;
  for (long long i = 0; i < n - na; ++i) a.push_back(0);
  for (long long i = 0; i < n - nb; ++i) b.push_back(0);
  fft(a, false);
  fft(b, false);
  for (long long i = 0; i < n; i++) {
    long long x = a[i] * b[i];
    f(x);
    a[i] = x;
  }
  fft(a, true);
  return a;
}
long long st(long long a, long long k) {
  if (k == 0) return 1;
  if (k == 1) return a;
  long long tmp = st(a, k / 2);
  tmp = g(tmp * tmp);
  if (k & 1) tmp = g(tmp * a);
  return tmp;
}
vector<long long> fact(maxn, 1);
void init() {
  for (long long i = 2; i < maxn; ++i) {
    long long x = i * 1ll * fact[i - 1];
    f(x);
    fact[i] = x;
  }
}
long long c(long long n, long long k) {
  long long x = fact[k] * 1ll * fact[n - k];
  f(x);
  x = st(x, mod - 2);
  x *= fact[n];
  f(x);
  return x;
}
vector<long long> solve(vector<vector<long long> > a) {
  long long m = a.size();
  if (!m) return {1};
  if (m == 1) return a[0];
  if (m == 2) {
    return multiply(a[0], a[1]);
  }
  vector<vector<long long> > l;
  for (long long i = 0; i < m / 2; ++i) l.push_back(a[i]);
  vector<vector<long long> > r;
  for (long long i = m / 2; i < m; ++i) r.push_back(a[i]);
  return multiply(solve(l), solve(r));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  init();
  long long n;
  cin >> n;
  for (long long i = 1; i < n; ++i) {
    long long u, v;
    cin >> u >> v;
    ++e[u];
    ++e[v];
  }
  vector<long long> cnt(n + 1, 0);
  for (long long i = 1; i <= n; ++i) {
    if (i > 1) --e[i];
    long long k = e[i];
    ++cnt[k];
  }
  vector<vector<long long> > a;
  for (long long i = 1; i <= n; ++i) {
    vector<long long> t = {1, e[i]};
    a.push_back(t);
  }
  vector<long long> s = solve(a);
  long long sol = 0, i = n, z = 1;
  for (long long x : s) {
    long long r = g(fact[i] * z * x);
    sol += r;
    f(sol);
    z *= -1;
    --i;
    if (i == -1) break;
  }
  cout << sol << '\n';
}
