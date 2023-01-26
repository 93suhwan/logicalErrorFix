#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = (1 << 18), G = 3, mod = 998244353, gg = (mod + 1) / G;
long long d[N], p[N], ans, n, rev[N];
long long qpow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y /= 2;
  }
  return res % mod;
}
void init() {
  p[0] = 1;
  for (long long i = 1; i <= n; i++) {
    p[i] = p[i - 1] * i % mod;
  }
}
void ntt(vector<long long>& f, long long op) {
  long long n = f.size();
  for (long long i = 0; i < n; i++)
    if (i < rev[i]) swap(f[i], f[rev[i]]);
  for (long long i = 1; i < n; i = i * 2) {
    long long w = qpow(op == 1 ? G : gg, (mod - 1) / 2 / i);
    for (long long j = 0; j < n; j += i + i) {
      long long wn = 1;
      for (long long k = 0; k < i; k++) {
        long long x = f[k + j], y = wn * f[i + k + j] % mod;
        f[k + j] = (x + y) % mod, f[k + j + i] = (x - y + mod) % mod;
        wn = wn * w % mod;
      }
    }
  }
}
vector<long long> multiply(vector<long long> const& a,
                           vector<long long> const& b) {
  long long n = 1, sz = a.size() + b.size() - 1;
  vector<long long> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  while (n < (long long)(a.size() + b.size())) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  for (long long i = 0; i < n; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
  ntt(fa, 0);
  ntt(fb, 0);
  for (long long i = 0; i < n; i++) fa[i] = fa[i] * fb[i] % mod;
  ntt(fa, 1);
  fa.resize(sz);
  long long inv = qpow(n, mod - 2);
  for (long long i = 0; i < sz; i++) fa[i] = fa[i] * inv % mod;
  return fa;
}
vector<long long> solve(long long l, long long r) {
  if (l == r) return {1, d[l] - (l != 1)};
  long long mid = (l + r) / 2;
  return multiply(solve(l, mid), solve(mid + 1, r));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  init();
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    d[u]++;
    d[v]++;
  }
  vector<long long> f = solve(1, n);
  for (long long i = 0; i <= n; i++) {
    if (i % 2)
      ans -= f[i] * p[n - i] % mod;
    else
      ans += f[i] * p[n - i] % mod;
    ans = (ans % mod + mod) % mod;
  }
  cout << ans << endl;
}
