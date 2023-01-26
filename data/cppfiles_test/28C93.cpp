#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using PQR = priority_queue<T, vector<T>, greater<T>>;
constexpr ll mod = 1000000007;
constexpr ll INF = 1000000099;
constexpr ll LINF = (ll)(1e18 + 99);
const ld PI = acos((ld)-1);
constexpr ll dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
template <typename T, typename U>
inline bool chmin(T& t, const U& u) {
  if (t > u) {
    t = u;
    return 1;
  }
  return 0;
}
template <typename T, typename U>
inline bool chmax(T& t, const U& u) {
  if (t < u) {
    t = u;
    return 1;
  }
  return 0;
}
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
inline void Yes() { cout << "Yes" << '\n'; }
inline void No() { cout << "No" << '\n'; }
inline void YES() { cout << "YES" << '\n'; }
inline void NO() { cout << "NO" << '\n'; }
template <typename T, typename Y>
inline T mpow(T a, Y n) {
  T res = 1;
  for (; n; n >>= 1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}
template <typename T>
vector<T> finddivisor(T x) {
  vector<T> divisor;
  for (T i = 1; (i * i) <= x; i++) {
    if (x % i == 0) {
      divisor.push_back(i);
      if (i * i != x) {
        divisor.push_back(x / i);
      }
    }
  }
  sort(divisor.begin(), divisor.end());
  return divisor;
}
template <typename T>
V<T> prefix_sum(const V<T>& v) {
  int n = v.size();
  V<T> ret(n + 1);
  for (ll i = 0; i < (ll)(n); ++i) ret[i + 1] = ret[i] + v[i];
  return ret;
}
template <typename T>
T rand(T l, T r) {
  static random_device rd;
  static mt19937 g(rd());
  return uniform_int_distribution<T>(l, r)(g);
}
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (auto&& x : vec) is >> x;
  return is;
}
template <typename T, typename Y>
ostream& operator<<(ostream& os, const pair<T, Y>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const V<T>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
template <typename... Args>
void debug(Args&... args) {
  for (auto const& x : {args...}) {
    cerr << x << ' ';
  }
  cerr << '\n';
}
template <typename T>
struct UnionFind {
  vector<T> Parent;
  UnionFind(T N) { Parent = vector<T>(N, -1); }
  T root(T A) {
    if (Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }
  T size(T A) { return -Parent[root(A)]; }
  bool connect(T A, T B) {
    A = root(A);
    B = root(B);
    if (A == B) return false;
    if (size(A) < size(B)) swap(A, B);
    Parent[A] += Parent[B];
    Parent[B] = A;
    return true;
  }
  bool same(T A, T B) { return root(A) == root(B); }
};
ll f(int rot, V<ll> p) {
  rotate(p.begin(), p.begin() + rot, p.end());
  ll n = (ll)(p).size();
  UnionFind<int> u(n);
  ll ans = 0;
  for (ll i = 0; i < (ll)(n); ++i)
    if (u.connect(i, p[i])) ans++;
  return ans;
}
signed main() {
  cin.tie(0);
  cerr.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int qq;
  cin >> qq;
  while (qq--) {
    ll n, m;
    cin >> n >> m;
    V<ll> p(n);
    cin >> p;
    for (ll i = 0; i < (ll)(n); ++i) p[i]--;
    V<ll> cnt(n, 0);
    for (ll i = 0; i < (ll)(n); ++i) {
      cnt[(i - p[i] + n) % n]++;
    }
    V<ll> ans(0);
    for (ll i = 0; i < (ll)(n); ++i) {
      if (cnt[i] == n)
        ans.push_back(i);
      else if ((n - cnt[i] + 1) / 2 <= m) {
        if (f(i, p) <= m) ans.push_back(i);
      }
    }
    cout << (ll)(ans).size() << " ";
    for (auto&& i : ans) cout << i << " ";
    cout << '\n';
  }
}
