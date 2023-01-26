#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long to, cost;
  edge() {}
  edge(long long a, long long b) { to = a, cost = b; }
};
const long long dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const long long mod = 998244353;
struct mint {
  long long x = 0;
  mint(long long y = 0) {
    x = y;
    if (x < 0 || x >= mod) x = (x % mod + mod) % mod;
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
    x *= ope.x, x %= mod;
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
mint comb(long long n, long long k) {
  if (n < 0 || k < 0 || n < k) return mint(0);
  return fact[n] * fact_inv[k] * fact_inv[n - k];
}
mint perm(long long n, long long k) { return comb(n, k) * fact[k]; }
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
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T>& deq) {
  for (int i = 0; i < deq.size(); i++)
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
  for (long long i = s; i <= t; i++) {
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
long long T;
long long n;
vector<long long> G[100005];
long long sum[100005];
long long cnt[100005];
mint dp[100005];
vector<long long> dvec[100005];
void dfs(int v, int p) {
  sum[v] += ((long long)(G[v]).size());
  for (auto u : G[v]) {
    if (u == p) continue;
    dfs(u, v);
    sum[v] += sum[u];
  }
}
void dfs2(int v, int p) {
  for (auto u : G[v]) {
    if (u == p) continue;
    long long S = sum[u], T = sum[1] - sum[u];
    long long g = gcd(S - 1, T + 1), h = gcd(S + 1, T - 1);
    vector<long long> vec = dvec[g];
    vec.insert(vec.end(), (dvec[h]).begin(), (dvec[h]).end());
    uniq(vec);
    for (auto x : vec) cnt[x]++;
    dfs2(u, v);
  }
}
long long deg[100005];
bool dfs3(int v, int p, int g) {
  if (sum[v] == 1) return true;
  for (auto u : G[v]) {
    if (u == p) continue;
    if (dfs3(u, v, g)) deg[v]++;
  }
  bool ret = true;
  if (deg[v] % g == g - 1)
    ret = false, deg[v]++;
  else if (deg[v] % g != 0)
    cnt[v] = 0;
  if (deg[v] > ((long long)(G[v]).size())) cnt[v] = 0;
  return ret;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = (1); (i) <= (100003); (i)++) {
    for (int j = 2 * i; j <= 100003; j += i) dvec[j].push_back(i);
  }
  cin >> T;
  while (T--) {
    cin >> n;
    long long u, v;
    for (long long i = (1); (i) <= (n); (i)++) G[i].clear();
    for (long long i = (1); (i) <= (n - 1); (i)++) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (long long i = (1); (i) <= (n); (i)++) sum[i] = cnt[i] = 0;
    dfs(1, -1), dfs2(1, -1);
    for (long long i = (1); (i) <= (n); (i)++) dp[i] = 0;
    for (long long i = (2); (i) <= (n); (i)++) {
      if (cnt[i] == n - 1) {
        for (long long j = (1); (j) <= (n); (j)++) deg[j] = 0;
        dfs3(1, -1, i);
      }
      if (cnt[i] == n - 1) dp[i] = 1;
    }
    dp[1] = modpow(mint(2), n - 1);
    for (long long i = (n); (i) >= (1); (i)--)
      for (int j = 2 * i; j <= n; j += i) dp[i] -= dp[j];
    outa(dp, 1, n);
  }
  return 0;
}
