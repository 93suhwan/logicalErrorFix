#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
template <int p>
struct mod_int {
  long long pow(long long b, long long e) {
    if (e == 0) return 1;
    long long r = pow(b * b % p, e / 2);
    if (e % 2 == 1) r = (r * b) % p;
    return r;
  }
  long long inv(long long b) { return pow(b, p - 2); }
  using m = mod_int;
  int v;
  mod_int() : v(0) {}
  mod_int(long long v_) {
    if (v_ >= p || v_ <= -p) v_ %= p;
    if (v_ < 0) v_ += p;
    v = v_;
  }
  m &operator+=(const m &a) {
    v += a.v;
    if (v >= p) v -= p;
    return *this;
  }
  m &operator-=(const m &a) {
    v -= a.v;
    if (v < 0) v += p;
    return *this;
  }
  m &operator*=(const m &a) {
    v = (v * long long(a.v)) % p;
    return *this;
  }
  m &operator/=(const m &a) {
    v = (v * inv(a.v)) % p;
    return *this;
  }
  m operator-() { return m(-v); }
  m &operator^=(long long e) {
    if (e < 0) {
      v = inv(v);
      e = -e;
    }
    v = pow(v, e % (p - 1));
    return *this;
  }
  bool operator==(const m &a) { return v == a.v; }
  bool operator!=(const m &a) { return v != a.v; }
  friend istream &operator>>(istream &in, m &a) {
    long long val;
    in >> val;
    a = m(val);
    return in;
  }
  friend ostream &operator<<(ostream &out, m a) { return out << a.v; }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend m operator^(m a, long long e) { return a ^= e; }
  static m rt(bool f, int n, int N) {
    if (p == 998244353) {
      m r(102292);
      int ord = (1 << 23);
      while (ord != N) {
        r = r * r;
        ord /= 2;
      }
      if (f) r = r ^ (-1);
      return r ^ (N / n);
    }
    return -1;
  }
};
const int MOD = 998244353;
template <typename T>
void fft(vector<T> &a, bool f, int N, vector<int> &rev) {
  for (int i = 0; i < N; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  int l, r, m;
  vector<T> roots(N);
  for (int n = 2; n <= N; n *= 2) {
    T root = T::rt(f, n, N);
    roots[0] = 1;
    for (int i = 1; i < n / 2; i++) roots[i] = roots[i - 1] * root;
    for (int pos = 0; pos < N; pos += n) {
      l = pos, r = pos + n / 2, m = 0;
      while (m < n / 2) {
        auto t = roots[m] * a[r];
        a[r] = a[l] - t, a[l] = a[l] + t;
        l++, m++, r++;
      }
    }
  }
  if (f) {
    auto invN = T(1) / N;
    for (int i = 0; i < N; i++) a[i] = a[i] * invN;
  }
}
template <typename T>
vector<T> convolution(vector<T> &a, vector<T> &b) {
  vector<T> l(a.begin(), a.end());
  vector<T> r(b.begin(), b.end());
  int ln = l.size(), rn = r.size();
  int N = ln + rn + 1, n = 1, log_n = 0;
  while (n <= N) {
    n <<= 1;
    log_n++;
  }
  vector<int> rev(n);
  for (int i = 0; i < n; ++i) {
    rev[i] = 0;
    for (int j = 0; j < log_n; ++j)
      if (i & (1 << j)) rev[i] |= 1 << (log_n - 1 - j);
  }
  assert(N <= n);
  l.resize(n), r.resize(n);
  fft(l, false, n, rev), fft(r, false, n, rev);
  for (int i = 0; i < n; i++) l[i] *= r[i];
  fft(l, true, n, rev);
  return l;
}
vector<int> deg;
vector<vector<int>> g;
void dfs(int v, int p = -1) {
  for (int u : g[v])
    if (u != p) deg[v]++, dfs(u, v);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n), deg.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(0);
  vector<mod_int<MOD>> fat(n + 1);
  fat[0] = 1;
  for (int i = 1; i <= n; i += 1) fat[i] = fat[i - 1] * i;
  vector<vector<mod_int<MOD>>> G;
  for (int d : deg) G.push_back({1, d});
  while (G.size() > 1) {
    vector<vector<mod_int<MOD>>> nG;
    for (int i = 0; i < int(G.size()) - 1; i += 2) {
      nG.push_back(convolution(G[i], G[i + 1]));
      if (nG.back().size() > n) nG.back().resize(n + 1);
      while (nG.back().size() > 1 and nG.back().back() == 0)
        nG.back().pop_back();
    }
    if (G.size() % 2 == 1) nG.push_back(G.back());
    G = nG;
  }
  mod_int<MOD> ans = fat[n];
  for (int i = 1, sgn = -1; i < min<int>(n, G[0].size()); i += 1, sgn *= -1)
    ans += sgn * fat[n - i] * G[0][i];
  cout << ans << '\n';
  return 0;
}
