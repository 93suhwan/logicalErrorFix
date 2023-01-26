#include <bits/stdc++.h>
using namespace std;
const int mod = (119 << 23) + 1, root = 3;
const long double pi = 4 * atan((long double)1);
int size(int s) { return s > 1 ? 32 - __builtin_clz(s - 1) : 0; }
int sum(int a, const int& b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
int sub(int a, const int& b) {
  if ((a -= b) < 0) a += mod;
  return a;
}
int mult(int a, const int& b) { return (1LL * a * b) % mod; }
int binpow(long long x, long long p) {
  int ans;
  for (ans = 1; p; p >>= 1) {
    if (p & 1LL) ans = mult(ans, x);
    x = mult(x, x);
  }
  return ans;
}
void genRoots(vector<complex<double>>& roots) {
  int n = roots.size();
  long double ang = 2 * pi / n;
  for (int i = 0; i < n; ++i)
    roots[i] = complex<double>(cos(ang * i), sin(ang * i));
}
void genRoots(vector<int>& roots) {
  int n = roots.size();
  int r = binpow(root, (mod - 1) / n);
  roots[0] = 1;
  for (int i = 1; i < n; ++i) roots[i] = mult(roots[i - 1], r);
}
void Fft(vector<int>& a, const vector<int>& roots, bool inv = 0) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n; i += len)
      for (int j = 0; j < len / 2; ++j) {
        int ind = n / len * j;
        if (inv && ind) ind = n - ind;
        int u = a[i + j], v = mult(a[i + j + len / 2], roots[ind]);
        a[i + j] = sum(u, v), a[i + j + len / 2] = sub(u, v);
      }
  if (inv) {
    int i = binpow(n, mod - 2);
    for (int& x : a) x = mult(x, i);
  }
}
vector<int> Mult(vector<int> a, vector<int> b) {
  int as = a.size(), bs = b.size();
  if (!min(as, bs)) return {};
  int s = as + bs - 1, n = 1 << size(s);
  vector<int> roots(n);
  genRoots(roots);
  a.resize(n);
  Fft(a, roots);
  b.resize(n);
  Fft(b, roots);
  for (int i = 0; i < n; ++i) a[i] = mult(a[i], b[i]);
  Fft(a, roots, true);
  a.resize(s);
  return a;
}
template <typename T, T mod>
struct Tint {
  T val;
  Tint() : val(0) {}
  Tint(long long x) {
    x %= mod;
    if (x < 0) x += mod;
    val = x;
  }
  Tint& operator+=(Tint oth) {
    val += oth.val;
    if (val >= mod) val -= mod;
    return *this;
  }
  Tint& operator-=(Tint oth) {
    val -= oth.val;
    if (val < 0) val += mod;
    return *this;
  }
  Tint& operator*=(Tint oth) {
    val = (long long)(val)*oth.val % mod;
    return *this;
  }
  Tint operator+(Tint oth) const { return Tint(*this) += oth; }
  Tint operator-(Tint oth) const { return Tint(*this) -= oth; }
  Tint operator*(Tint oth) const { return Tint(*this) *= oth; }
};
using Mint = Tint<int, mod>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> deg(n, 0);
  function<void(int, int)> dfs = [&](int u, int p) {
    for (int v : adj[u])
      if (v != p) {
        deg[u]++;
        dfs(v, u);
      }
  };
  dfs(0, -1);
  priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                 greater<pair<int, vector<int>>>>
      pq;
  for (int i = 0; i < n; ++i) {
    vector<int> v = {1, deg[i]};
    pq.push(pair<int, vector<int>>(2, v));
  }
  while (pq.size() > 1) {
    auto a = pq.top().second;
    pq.pop();
    auto b = pq.top().second;
    pq.pop();
    auto res = Mult(a, b);
    pq.push(pair<int, vector<int>>(res.size(), res));
  }
  auto poly = pq.top().second;
  while (poly.size() < n) {
    poly.push_back(0);
  }
  vector<Mint> fact(n + 1);
  fact[0] = 1;
  for (int i = 0; i < n; ++i) {
    fact[i + 1] = fact[i] * (i + 1);
  }
  Mint ans = 0;
  for (int i = 0; i < n; ++i) {
    Mint ways = fact[n - i] * poly[i];
    if (i % 2 == 1) ways *= -1;
    ans += ways;
  }
  cout << ans.val << '\n';
  return 0;
}
