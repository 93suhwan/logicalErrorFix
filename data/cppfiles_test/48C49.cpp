#include <bits/stdc++.h>
using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
const pair<int, int> DD[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int mod = 1e9 + 7, mxN = 2e5 + 5, INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
template <typename... T>
void print(T... args) {
  ((cout << args << " "), ...), cout << endl;
}
template <typename... T>
void dbgout(string vars, T... args) {
  cout << endl;
  cout << "[";
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << args, delim = ", "));
  cout << "]";
  cout << endl;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& ot, pair<T1, T2>& p) {
  ot << p.first << ' ' << p.second;
  return ot;
}
template <typename T1, typename T2>
bool cmax(T1& a, T2 b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
bool cmin(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (T& x : v) in >> x;
  return in;
}
template <typename T>
ostream& operator<<(ostream& ot, vector<T>& v) {
  for (T& x : v) ot << x << ' ';
  return ot;
}
template <typename T>
ostream& operator<<(ostream& ot, set<T>& s) {
  for (T x : s) ot << x << ' ';
  return ot;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& ot, map<T1, T2>& M) {
  for (auto& [x, y] : M) ot << "(" << x << " : " << y << ")" << endl;
  return ot;
}
template <typename T>
using pq = priority_queue<T, vector<T>, greater<T>>;
ll mod_pow(ll x, ll y) {
  ll res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
ll mod_inv(ll n) {
  ll ans = mod_pow(n, mod - 2);
  return ans;
}
ll mul(ll a, ll b) {
  a %= mod, b %= mod;
  return (a * b) % mod;
}
ll sub(ll a, ll b) {
  a %= mod, b %= mod;
  return (a - b + mod) % mod;
}
ll add(ll a, ll b) {
  a %= mod, b %= mod;
  return (a + b) % mod;
}
bool _prime(ll n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (ll i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  return 1;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T, class first = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  first func;
  SparseTable(const vector<T>& a, const first& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};
template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) { fenw.resize(n); }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};
void solve() {
  int n, q, L, R;
  cin >> n >> q;
  vi A(n), B(n);
  cin >> A >> B;
  vl dif(n + 1);
  for (int i = 0; i < (int)(n); i++) dif[i + 1] = dif[i] + B[i] - A[i];
  SparseTable<ll> mn(dif, [](ll i, ll j) { return min(i, j); });
  SparseTable<ll> mx(dif, [](ll i, ll j) { return max(i, j); });
  while (q--) {
    cin >> L >> R;
    if (dif[R] - dif[L - 1] != 0) {
      print(-1);
      continue;
    }
    if (mn.get(L, R) < dif[L - 1]) {
      print(-1);
      continue;
    }
    print(mx.get(L - 1, R) - dif[L - 1]);
  }
}
int main() {
  cout << fixed << setprecision(12);
  cin.tie(0)->sync_with_stdio(0), cin.exceptions(cin.failbit);
  solve();
  return 0;
}
