#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
struct ntt {
 private:
  vector<vector<long long>> w, w_inv;
  long long g;
  long long _g;
  long long _2;
  long long LOG = 20;
  long long cntr = 0;
  long long power(long long a, long long b, long long mod) {
    if (a == 0 and b == 0) return 1;
    if (a == 0) return 0;
    if (b == 0) return 1;
    if (b == 1) return a;
    long long x = power(a, b / 2, mod);
    x = (1ll * x * x) % mod;
    if (b % 2) x = (1ll * x * a) % mod;
    return x;
  }
  void pre() {
    cntr++;
    _g = power(g, mod - 2, mod);
    _2 = power(2, mod - 2, mod);
    long long n = power(2, LOG, mod);
    w = vector<vector<long long>>(LOG + 1);
    w_inv = vector<vector<long long>>(LOG + 1);
    for (long long i = LOG; i >= 0; i--) {
      w[i] = vector<long long>(i + 1);
      w_inv[i] = vector<long long>(i + 1);
      w[i][i] = power(g, (mod - 1) / n, mod);
      w_inv[i][i] = power(_g, (mod - 1) / n, mod);
      for (long long j = i - 1; j >= 0; j--) {
        w[i][j] = (1ll * w[i][j + 1] * w[i][j + 1]) % mod;
        w_inv[i][j] = (1ll * w_inv[i][j + 1] * w_inv[i][j + 1]) % mod;
      }
      n /= 2;
    }
  }
  void NTT(vector<long long> &a, bool inv, long long _N, long long _i) {
    if (int(a.size()) == 1) return;
    long long n = (long long)a.size();
    vector<long long> a0(n / 2), a1(n / 2);
    for (long long i = 0; i < n; i += 2) {
      a0[i / 2] = (a[i]);
      a1[i / 2] = (a[i + 1]);
    }
    NTT(a0, inv, _N, _i - 1);
    NTT(a1, inv, _N, _i - 1);
    long long w0 = 1, _w = (!inv ? w[_N][_i] : w_inv[_N][_i]);
    for (long long i = 0; i < n / 2; i++) {
      a[i] = (a0[i] + (1ll * w0 * a1[i]) % mod) % mod;
      a[i + n / 2] = (a0[i] - (1ll * w0 * a1[i]) % mod + mod) % mod;
      if (inv) {
        a[i] = (1ll * _2 * a[i]) % mod;
        a[i + n / 2] = (1ll * _2 * a[i + n / 2]) % mod;
      }
      w0 = (1ll * w0 * _w) % mod;
    }
  }

 public:
  ntt() : g(3) { pre(); }
  vector<long long> multiply(vector<long long> &a, vector<long long> &b) {
    assert(cntr == 1);
    vector<long long> fa = a;
    vector<long long> fb = b;
    long long n = 1;
    long long _n = 0;
    while (n < (long long)a.size() + (long long)b.size()) n *= 2, _n++;
    fa.resize(n);
    fb.resize(n);
    NTT(fa, 0, _n, _n);
    NTT(fb, 0, _n, _n);
    for (long long i = 0; i < (long long)fa.size(); i++)
      fa[i] = (1ll * fa[i] * fb[i]) % mod;
    NTT(fa, 1, _n, _n);
    return fa;
  }
};
void solve() {
  long long n;
  cin >> n;
  vector<long long> deg(n, -1);
  deg[0] = 0;
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    a--, b--;
    deg[a]++;
    deg[b]++;
  }
  vector<vector<long long>> poly(n);
  using node = pair<long long, vector<long long>>;
  priority_queue<node, vector<node>, greater<node>> pq;
  for (long long i = 0; i < n; i++) {
    poly[i] = vector<long long>{1, deg[i]};
    pq.push({2, poly[i]});
  }
  ntt x;
  while (!pq.empty()) {
    auto a = pq.top().second;
    pq.pop();
    if (pq.empty()) {
      pq.push({int(a.size()), a});
      break;
    }
    auto b = pq.top().second;
    pq.pop();
    auto c = x.multiply(a, b);
    pq.push({int(c.size()), c});
  }
  auto a = pq.top().second;
  pq.pop();
  long long res = 0;
  vector<long long> f(n + 1, 1);
  for (long long i = 1; i <= n; i++) {
    f[i] = f[i - 1] * i;
    f[i] %= mod;
  }
  for (long long i = 0; i <= n; i++) {
    if (i % 2 == 0)
      res = res + (1ll * f[n - i] * a[i]) % mod;
    else
      res = res + mod - (1ll * f[n - i] * a[i]) % mod;
    res %= mod;
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
