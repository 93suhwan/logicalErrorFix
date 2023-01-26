#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1000000007;
const long long INF = mod * mod;
const double eps = 1e-8;
const double pi = acosl(-1.0);
long long mod_pow(long long x, long long n, long long m = mod) {
  if (n < 0) {
    long long res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m) x %= m;
  if (x < 0) x += m;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
struct modint {
  long long n;
  modint() : n(0) { ; }
  modint(long long m) : n(m) {
    if (n >= mod)
      n %= mod;
    else if (n < 0)
      n = (n % mod + mod) % mod;
  }
  operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) {
  a.n += b.n;
  if (a.n >= mod) a.n -= mod;
  return a;
}
modint operator-=(modint& a, modint b) {
  a.n -= b.n;
  if (a.n < 0) a.n += mod;
  return a;
}
modint operator*=(modint& a, modint b) {
  a.n = ((long long)a.n * b.n) % mod;
  return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, long long n) {
  if (n == 0) return modint(1);
  modint res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}
long long inv(long long a, long long p) {
  return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) {
  a = a / b;
  return a;
}
const int max_n = 1 << 2;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = modint(1);
  for (int i = 0; i < max_n - 1; i++) {
    fact[i + 1] = fact[i] * modint(i + 1);
  }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1];
  for (int i = max_n - 2; i >= 0; i--) {
    factinv[i] = factinv[i + 1] * modint(i + 1);
  }
}
modint comb(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[a - b];
}
using mP = pair<modint, modint>;
struct Data {
  int t, col;
  modint sum;
};
modint ans = 0;
int K;
vector<int> a;
struct edge {
  int to, col;
};
const int mn = 1 << 18;
vector<edge> G[mn];
queue<vector<int>> q;
bool exi[mn];
void yaru(vector<int> v) {
  if (v.empty()) return;
  for (int id : v) exi[id] = true;
  int g;
  int sz = v.size();
  function<int(int, int)> s_root = [&](int id, int fr) -> int {
    int res = 1;
    int ma = 0;
    for (edge e : G[id]) {
      if (e.to == fr) continue;
      if (!exi[e.to]) continue;
      int nex = s_root(e.to, id);
      ma = max(ma, nex);
      res += nex;
    }
    if (ma <= sz / 2 && sz - res <= sz / 2) g = id;
    return res;
  };
  s_root(v[0], -1);
  vector<mP> psum[2];
  vector<vector<mP>> sum[2];
  vector<vector<Data>> datas;
  modint csum = 0;
  for (edge e : G[g])
    if (exi[e.to]) {
      int tmp = datas.size();
      datas.push_back({});
      function<void(int, int, Data)> dfs = [&](int id, int fr, Data d) {
        if (!exi[id]) return;
        datas[tmp].push_back({d.t, e.col, d.sum});
        for (edge e : G[id]) {
          if (e.to == fr) continue;
          Data nd = d;
          if (d.col != e.col) nd.t++;
          nd.col = e.col;
          nd.sum += a[e.to];
          dfs(e.to, id, nd);
        }
      };
      dfs(e.to, g, {0, e.col, a[e.to]});
    }
  auto add = [&](vector<mP>& v, mP p, int loc) {
    while (v.size() <= loc) v.push_back({0, 0});
    v[loc].first += p.first;
    v[loc].second += p.second;
  };
  auto matome = [&](vector<mP>& v) {
    for (int i = 0; i < (int)v.size(); i++)
      if (i > 0) {
        v[i].first += v[i - 1].first;
        v[i].second += v[i - 1].second;
      }
  };
  for (int j = 0; j < 2; j++) {
    sum[j].resize(datas.size());
  }
  for (int i = 0; i < datas.size(); i++) {
    for (Data d : datas[i]) {
      if (d.t <= K) {
        csum += (modint)2 * (d.sum + (modint)a[g]);
      }
      add(psum[d.col], {d.sum, 1}, d.t);
      add(sum[d.col][i], {d.sum, 1}, d.t);
    }
  }
  for (int j = 0; j < 2; j++) {
    matome(psum[j]);
    for (int i = 0; i < datas.size(); i++) {
      matome(sum[j][i]);
    }
  }
  for (int i = 0; i < datas.size(); i++) {
    for (Data d : datas[i]) {
      for (int j = 0; j < 2; j++) {
        int sup = K - d.t;
        if (j != d.col) sup--;
        if (sup >= 0) {
          modint val = 0;
          if (psum[j].size()) {
            int loc = min(sup, (int)psum[j].size() - 1);
            int cnt = psum[j][loc].second;
            val += (d.sum + (modint)a[g]) * (modint)cnt + psum[j][loc].first;
          }
          if (sum[j][i].size()) {
            int loc = min(sup, (int)sum[j][i].size() - 1);
            int cnt = sum[j][i][loc].second;
            val -= (d.sum + (modint)a[g]) * (modint)cnt + sum[j][i][loc].first;
            assert(psum[j].size());
          }
          csum += val;
        }
      }
    }
  }
  ans += csum;
  vector<vector<int>> chs;
  vector<int> nexs;
  function<void(int, int)> search_next = [&](int id, int fr) {
    if (!exi[id]) return;
    nexs.push_back(id);
    for (edge e : G[id]) {
      if (e.to == fr) continue;
      search_next(e.to, id);
    }
  };
  for (edge e : G[g]) {
    search_next(e.to, g);
    if (nexs.empty()) continue;
    q.push(nexs);
    chs.push_back(nexs);
    nexs.clear();
  }
  for (int id : v) exi[id] = false;
}
void uoo(int n) {
  vector<int> ori(n);
  for (int i = 0; i < n; i++) ori[i] = i;
  q.push(ori);
  while (!q.empty()) {
    vector<int> v = q.front();
    q.pop();
    yaru(v);
  }
}
void solve() {
  int n;
  cin >> n >> K;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  uoo(n);
  ans /= 2;
  for (int i = 0; i < n; i++) ans += a[i];
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
