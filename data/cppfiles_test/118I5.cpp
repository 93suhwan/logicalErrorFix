#include <bits/stdc++.h>
using namespace std;
using cd = complex<long double>;
const long double PI = acos(-1);
void fft(vector<cd>& a, bool invert) {
  long long n = a.size();
  if (n == 1) return;
  vector<cd> a0(n / 2), a1(n / 2);
  for (long long i = 0; 2 * i < n; i++) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }
  fft(a0, invert);
  fft(a1, invert);
  long double ang = 2 * PI / n * (invert ? -1 : 1);
  cd w(1), wn(cos(ang), sin(ang));
  for (long long i = 0; 2 * i < n; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    if (invert) {
      a[i] /= 2;
      a[i + n / 2] /= 2;
    }
    w *= wn;
  }
}
const long long maxn = 250050;
const long long mod = 998244353;
vector<long long> e[maxn], p(maxn);
void f(long long& x) {
  if (abs(x) >= mod) x %= mod;
  if (x < 0) x += mod;
}
long long g(long long x) {
  f(x);
  return x;
}
vector<long long> multiply(vector<long long> const& a,
                           vector<long long> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  long long n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (long long i = 0; i < n; i++) {
    fa[i] *= fb[i];
  }
  fft(fa, true);
  vector<long long> result(n);
  for (long long i = 0; i < n; i++) {
    result[i] = round(fa[i].real());
    f(result[i]);
  }
  return result;
}
void dfs(long long x, long long st) {
  for (auto& i : e[x]) {
    if (i == st) continue;
    p[i] = x;
    dfs(i, x);
  }
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
  for (long long i = 2; i < maxn; ++i) fact[i] = g(fact[i - 1] * i);
}
long long c(long long n, long long k) {
  return g(fact[n] * st(g(fact[k] * fact[n - k]), mod - 2));
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
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 1);
  vector<long long> cnt(n + 1, 0);
  for (long long i = 1; i <= n; ++i) {
    long long k = e[i].size();
    if (i > 1) --k;
    ++cnt[k];
  }
  vector<long long> a = {1};
  for (long long i = n; i >= 1; --i) {
    if (!cnt[i]) continue;
    vector<long long> t;
    long long m = cnt[i];
    for (long long j = 0; j <= m; ++j) {
      long long s = g(c(m, j) * st(i, j));
      t.push_back(s);
    }
    vector<long long> b = multiply(a, t);
    a = b;
  }
  long long sol = 0, i = n, z = 1;
  for (long long x : a) {
    long long r = g(fact[i] * z * x);
    sol += r;
    f(sol);
    z *= -1;
    --i;
    if (i == -1) break;
  }
  cout << sol << '\n';
}
