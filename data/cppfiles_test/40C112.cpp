#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
using namespace std;
struct edge {
  long long to, cost;
  edge() {}
  edge(long long a, long long b) { to = a, cost = b; }
};
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int mod = 1000000007;
struct mint {
  int x;
  mint(long long y = 0) {
    if (y < 0 || y >= mod) y = (y % mod + mod) % mod;
    x = y;
  }
  mint(const mint& ope) { x = ope.x; }
  mint operator-() { return mint(-x); }
  mint operator+(const mint& ope) { return mint(x) += ope; }
  mint operator-(const mint& ope) { return mint(x) -= ope; }
  mint operator*(const mint& ope) { return mint(x) *= ope; }
  mint operator/(const mint& ope) { return mint(x) /= ope; }
  mint& operator+=(const mint& ope) {
    x += ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& ope) {
    x += mod - ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint& ope) {
    long long tmp = x;
    tmp *= ope.x, tmp %= mod;
    x = tmp;
    return *this;
  }
  mint& operator/=(const mint& ope) {
    long long n = mod - 2;
    mint mul = ope;
    while (n) {
      if (n & 1) *this *= mul;
      mul *= mul;
      n >>= 1;
    }
    return *this;
  }
  mint inverse() { return mint(1) / *this; }
  bool operator==(const mint& ope) { return x == ope.x; }
  bool operator!=(const mint& ope) { return x != ope.x; }
  bool operator<(const mint& ope) { return x < ope.x; }
};
mint modpow(mint a, long long n) {
  if (n == 0) return mint(1);
  if (n % 2)
    return a * modpow(a, n - 1);
  else
    return modpow(a * a, n / 2);
}
istream& operator>>(istream& is, mint& ope) {
  long long t;
  is >> t, ope.x = t;
  return is;
}
ostream& operator<<(ostream& os, mint& ope) { return os << ope.x; }
ostream& operator<<(ostream& os, const mint& ope) { return os << ope.x; }
vector<mint> fact, fact_inv;
void make_fact(int n) {
  fact.resize(n + 1), fact_inv.resize(n + 1);
  fact[0] = mint(1);
  for (long long i = (1); (i) <= (n); (i)++) fact[i] = fact[i - 1] * mint(i);
  fact_inv[n] = fact[n].inverse();
  for (long long i = (n - 1); (i) >= (0); (i)--)
    fact_inv[i] = fact_inv[i + 1] * mint(i + 1);
}
mint comb(int n, int k) {
  if (n < 0 || k < 0 || n < k) return mint(0);
  return fact[n] * fact_inv[k] * fact_inv[n - k];
}
mint perm(int n, int k) { return comb(n, k) * fact[k]; }
vector<int> prime, pvec;
void make_prime(int n) {
  prime.resize(n + 1);
  for (long long i = (2); (i) <= (n); (i)++) {
    if (prime[i]) continue;
    for (int j = i; j <= n; j += i) prime[j] = i;
  }
  for (long long i = (2); (i) <= (n); (i)++)
    if (prime[i] == i) pvec.push_back(i);
}
bool exceed(long long x, long long y, long long m) { return x >= m / y + 1; }
void mark() { cout << "*" << endl; }
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
long long floor(long long a, long long b) {
  if (b < 0) a *= -1, b *= -1;
  if (a >= 0)
    return a / b;
  else
    return -((-a + b - 1) / b);
}
long long ceil(long long a, long long b) {
  if (b < 0) a *= -1, b *= -1;
  if (a >= 0)
    return (a + b - 1) / b;
  else
    return -((-a) / b);
}
long long modulo(long long a, long long b) {
  b = abs(b);
  return a - floor(a, b) * b;
}
long long sgn(long long x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long digitnum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret++;
  return ret;
}
long long digitsum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret += x % b;
  return ret;
}
string lltos(long long x) {
  string ret;
  for (; x; x /= 10) ret += x % 10 + '0';
  reverse(ret.begin(), ret.end());
  return ret;
}
long long stoll(string& s) {
  long long ret = 0;
  for (auto c : s) ret *= 10, ret += c - '0';
  return ret;
}
template <typename T>
void uniq(T& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
template <class S, class T>
pair<S, T>& operator+=(pair<S, T>& s, const pair<S, T>& t) {
  s.first += t.first, s.second += t.second;
  return s;
}
template <class S, class T>
pair<S, T>& operator-=(pair<S, T>& s, const pair<S, T>& t) {
  s.first -= t.first, s.second -= t.second;
  return s;
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T>& s, const pair<S, T>& t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T>& s, const pair<S, T>& t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  for (long long i = 0; (i) < (long long)(vec).size(); (i)++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (long long i = 0; (i) < (long long)(vec).size(); (i)++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T>& deq) {
  for (long long i = 0; (i) < (long long)(deq).size(); (i)++)
    os << deq[i] << (i + 1 == deq.size() ? "" : " ");
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
  for (typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end();
       itr++) {
    os << "(" << itr->first << ", " << itr->second << ")";
    itr++;
    if (itr != map_var.end()) os << ",";
    itr--;
  }
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
  for (typename set<T>::iterator itr = set_var.begin(); itr != set_var.end();
       itr++) {
    os << *itr;
    ++itr;
    if (itr != set_var.end()) os << " ";
    itr--;
  }
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, multiset<T>& set_var) {
  for (typename multiset<T>::iterator itr = set_var.begin();
       itr != set_var.end(); itr++) {
    os << *itr;
    ++itr;
    if (itr != set_var.end()) os << " ";
    itr--;
  }
  return os;
}
template <typename T>
void outa(T a[], long long s, long long t) {
  for (long long i = (s); (i) <= (t); (i)++) {
    cout << a[i];
    if (i < t) cout << " ";
  }
  cout << endl;
}
void dump_func() { cout << endl; }
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail) > 0) cout << " ";
  dump_func(std::move(tail)...);
}
struct UnionFind {
  int size;
  vector<int> parent;
  vector<int> rank;
  vector<long long> v, e;
  UnionFind() {}
  UnionFind(int size) {
    this->size = size;
    parent.resize(size + 1);
    rank.resize(size + 1);
    v.resize(size + 1);
    e.resize(size + 1);
    init();
  }
  void init() {
    for (int i = 0; i <= size; i++) {
      parent[i] = i, rank[i] = 0;
      v[i] = 1, e[i] = 0;
    }
  }
  int root(int i) {
    if (parent[i] == i) return i;
    return parent[i] = root(parent[i]);
  }
  bool same(int i, int j) { return root(i) == root(j); }
  void merge(int i, int j) {
    parent[i] = j;
    v[j] += v[i];
    e[j] += e[i] + 1;
  }
  void unite(int i, int j) {
    int root_i = root(i), root_j = root(j);
    if (root_i == root_j) {
      e[root_i]++;
      return;
    }
    if (rank[root_i] < rank[root_j])
      merge(root_i, root_j);
    else
      merge(root_j, root_i);
    if (rank[root_i] == rank[root_j]) rank[root_i]++;
  }
};
struct LCA {
  int n, logn;
  vector<vector<int> > prev;
  vector<int> depth;
  LCA() {}
  void predfs(vector<long long> G[], int v, int p, int d) {
    depth[v] = d, prev[v][0] = p;
    for (auto u : G[v]) {
      if (u == p) continue;
      predfs(G, u, v, d + 1);
    }
  }
  void init(vector<long long> G[], int n, int root = 1) {
    this->n = n;
    for (int i = 0;; i++) {
      if (n <= (1 << i)) {
        logn = i;
        break;
      }
    }
    prev.resize(n + 1);
    for (int i = 0; i < prev.size(); i++) prev[i].resize(logn);
    depth.resize(n + 1);
    prev[0][0] = 0;
    predfs(G, root, 0, 0);
    for (int i = 1; i < logn; i++) {
      for (int j = 0; j <= n; j++) {
        prev[j][i] = prev[prev[j][i - 1]][i - 1];
      }
    }
  }
  int getLCA(int u, int v) {
    int x = u, y = v;
    if (depth[y] > depth[x]) swap(x, y);
    for (int i = logn - 1; i >= 0; i--) {
      if (depth[x] - (1 << i) >= depth[y]) x = prev[x][i];
    }
    if (x == y) return x;
    for (int i = logn - 1; i >= 0; i--) {
      if (prev[x][i] != prev[y][i]) {
        x = prev[x][i];
        y = prev[y][i];
      }
    }
    x = prev[x][0];
    return x;
  }
};
long long n, m, Q;
vector<long long> G[300005];
UnionFind uf(300005);
LCA lca;
long long s[300005], t[300005];
long long cnt[300005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  long long u, v;
  for (long long i = (1); (i) <= (m); (i)++) {
    cin >> u >> v;
    if (uf.same(u, v)) continue;
    uf.unite(u, v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  lca.init(G, n);
  cin >> Q;
  for (long long i = (1); (i) <= (Q); (i)++) {
    cin >> s[i] >> t[i];
    cnt[s[i]]++, cnt[t[i]]++;
  }
  long long ans = 0;
  for (long long i = (1); (i) <= (n); (i)++) {
    if (cnt[i] % 2) ans++;
  }
  if (ans) {
    no();
    dump_func(ans / 2);
    return 0;
  }
  yes();
  for (long long i = (1); (i) <= (Q); (i)++) {
    long long l = lca.getLCA(s[i], t[i]);
    vector<long long> vec, vec2;
    long long v = s[i];
    while (v != l) {
      vec.push_back(v);
      v = lca.prev[v][0];
    }
    v = t[i];
    while (v != l) {
      vec2.push_back(v);
      v = lca.prev[v][0];
    }
    vec.push_back(l);
    reverse((vec2).begin(), (vec2).end());
    vec.insert(vec.end(), (vec2).begin(), (vec2).end());
    cout << ((long long)(vec).size()) << "\n";
    for (auto v : vec) cout << v << " ";
    cout << "\n";
  }
  return 0;
}
