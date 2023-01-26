#include <bits/stdc++.h>
using namespace std;
template <typename F, typename S>
ostream& operator<<(ostream& ostream, pair<F, S>& p) {
  cout << p.first << " " << p.second;
  return ostream;
}
template <typename T>
ostream& operator<<(ostream& ostream, vector<T>& v) {
  for (auto& element : v) {
    cout << element << " ";
  }
  return ostream;
}
template <typename T>
ostream& operator<<(ostream& ostream, vector<vector<T>>& v) {
  for (auto& row : v) {
    for (auto& cell : row) {
      cout << cell << " ";
    }
    cout << "\n";
  }
  return ostream;
}
template <typename F, typename S>
istream& operator>>(istream& istream, pair<F, S>& p) {
  cin >> p.first >> p.second;
  return istream;
}
template <typename T>
istream& operator>>(istream& istream, vector<T>& v) {
  for (auto& element : v) {
    cin >> element;
  }
  return istream;
}
constexpr int mod = 998244353;
const long long infinity = 1000000000000000000;
const int inf = 1e9 + 5;
const long long root = 62;
long long modpow(long long b, long long e) {
  long long ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
void ntt(vector<long long>& a) {
  int n = (int)(a).size(), L = 31 - __builtin_clz(n);
  static vector<long long> rt(2, 1);
  for (static int k = 2, s = 2; k < n; k *= 2, s++) {
    rt.resize(n);
    long long z[] = {1, modpow(root, mod >> s)};
    for (int i = k; i < (2 * k); ++i) rt[i] = rt[i / 2] * z[i & 1] % mod;
  }
  vector<int> rev(n);
  for (int i = 0; i < (n); ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  for (int i = 0; i < (n); ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k)
      for (int j = 0; j < (k); ++j) {
        long long z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
        a[i + j + k] = ai - z + (z > ai ? mod : 0);
        ai += (ai + z >= mod ? z - mod : z);
      }
}
vector<long long> conv(const vector<long long>& a, const vector<long long>& b) {
  if (a.empty() || b.empty()) return {};
  int s = (int)(a).size() + (int)(b).size() - 1, B = 32 - __builtin_clz(s),
      n = 1 << B;
  int inv = modpow(n, mod - 2);
  vector<long long> L(a), R(b), out(n);
  L.resize(n), R.resize(n);
  ntt(L), ntt(R);
  for (int i = 0; i < (n); ++i)
    out[-i & (n - 1)] = (long long)L[i] * R[i] % mod * inv % mod;
  ntt(out);
  return {out.begin(), out.begin() + s};
}
template <int MOD = mod>
struct Mint {
  int value;
  Mint(long long v = 0) {
    value = v % MOD;
    if (value < 0) value += MOD;
  }
  Mint(long long a, long long b) : value(0) {
    *this += a;
    *this /= b;
  }
  Mint& operator+=(Mint const& b) {
    value += b.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  Mint& operator-=(Mint const& b) {
    value -= b.value;
    if (value < 0) value += MOD;
    return *this;
  }
  Mint& operator*=(Mint const& b) {
    value = (long long)value * b.value % MOD;
    return *this;
  }
  Mint mexp(Mint a, long long e) {
    Mint res = 1;
    while (e) {
      if (e & 1) res *= a;
      a *= a;
      e >>= 1;
    }
    return res;
  }
  Mint inverse(Mint a) { return mexp(a, MOD - 2); }
  Mint& operator/=(Mint const& b) { return *this *= inverse(b); }
  friend Mint operator+(Mint a, Mint const b) { return a += b; }
  friend Mint operator-(Mint a, Mint const b) { return a -= b; }
  friend Mint operator-(Mint const a) { return 0 - a; }
  friend Mint operator*(Mint a, Mint const b) { return a *= b; }
  friend Mint operator/(Mint a, Mint const b) { return a /= b; }
  friend std::istream& operator>>(std::istream& istream, Mint& a) {
    long long v;
    istream >> v;
    a = v;
    return istream;
  }
  friend std::ostream& operator<<(std::ostream& ostream, Mint const& a) {
    return ostream << a.value;
  }
  friend bool operator==(Mint const& a, Mint const& b) {
    return a.value == b.value;
  }
  friend bool operator!=(Mint const& a, Mint const& b) {
    return a.value != b.value;
  }
};
using mint = Mint<mod>;
vector<mint> factorial, mmi;
void precompute_factorials(int maxnum) {
  factorial.assign(maxnum, 1);
  mmi.assign(maxnum, 1);
  for (int i = 2; i < maxnum; i++) {
    factorial[i] = factorial[i - 1] * i;
  }
  mmi[maxnum - 1] = 1 / factorial[maxnum - 1];
  for (int i = maxnum - 2; i >= 2; i--) {
    mmi[i] = mmi[i + 1] * (i + 1);
  }
}
mint nCr(long long n, long long r) {
  if (n < r) {
    return 0;
  }
  if (n == r) {
    return 1;
  }
  if (r == 0) {
    return 1;
  }
  return (factorial[n] * mmi[r] * mmi[n - r]);
}
int n_nodes, n_edges;
vector<vector<int>> adj;
vector<int> ch;
void graph_init() {
  adj.clear();
  adj.resize(n_nodes);
  ch.assign(n_nodes, 0);
}
void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void dfs(int v, int p = -1) {
  for (int u : adj[v]) {
    if (u == p) {
      continue;
    }
    dfs(u, v);
    ch[v]++;
  }
}
void solve() {
  cin >> n_nodes;
  n_edges = n_nodes - 1;
  graph_init();
  for (int e = 0; e < n_edges; e++) {
    int u, v;
    cin >> u >> v;
    add_edge(u - 1, v - 1);
  }
  dfs(0);
  vector<vector<long long>> pol;
  set<pair<int, int>> deg;
  for (int i = 0; i < n_nodes; i++) {
    pol.push_back({});
    pol.back().push_back(1);
    pol.back().push_back(ch[i]);
    deg.insert(make_pair(1, i));
  }
  while ((int)deg.size() > 1) {
    auto p1 = *(deg.begin());
    deg.erase(deg.begin());
    auto p2 = *(deg.begin());
    deg.erase(deg.begin());
    pol[p1.second] = conv(pol[p1.second], pol[p2.second]);
    deg.insert(make_pair(p1.first + p2.first, p1.second));
  }
  mint ans = 0;
  int id = (*(deg.begin())).second;
  for (int k = 0; k < n_nodes; k++) {
    int mul = 1;
    if (k & 1) mul *= -1;
    ans += mul * pol[id][k] * factorial[n_nodes - k];
  }
  cout << ans << "\n";
}
int main() {
  precompute_factorials(2e5 + 10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC = 1;
  for (int tc = 1; tc <= TC; tc++) {
    solve();
  }
  return 0;
}
