#include <bits/stdc++.h>
using namespace std;
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }
string to_string(const char* s) { return string(s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  string res;
  for (int i = 0; i < (int)v.size(); i++) res += char('0' + v[i]);
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using V = vector<T>;
template <typename T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
const long long dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
using ll = long long;
using db = long double;
using vd = vector<db>;
using vs = vector<string>;
using pi = pair<long long, long long>;
using vi = vector<long long>;
using vb = vector<bool>;
using vl = vector<ll>;
using vpi = vector<pi>;
template <class A>
void read(V<A>& v);
template <class A, size_t S>
void read(array<A, S>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(V<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t S>
void read(array<A, S>& x) {
  for (auto& a : x) read(a);
}
const long long mod = 998244353;
const ll INF = 1e18;
const db PI = acos((db)-1);
constexpr long long pct(long long x) { return __builtin_popcount(x); }
constexpr long long bits(long long x) {
  return x == 0 ? 0 : 31 - __builtin_clz(x);
}
constexpr long long p2(long long x) { return 1 << x; }
constexpr long long msk2(long long x) { return p2(x) - 1; }
template <typename T>
T binpow(T a, T b) {
  T ans = 1;
  while (b) {
    if (b & 1) {
      ans = 1LL * ans * a % mod;
    }
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vi a(n);
  read(a);
  V<vi> dp(n + 100, vi(2, 0));
  for (long long i = (0); i < (n); ++i) {
    long long x = a[i];
    dp[x][0] = (2 * dp[x][0] + (x >= 2 ? dp[x - 2][1] : 0)) % mod;
    dp[x][1] =
        (2 * dp[x][1] + (x >= 1 ? dp[x - 1][1] : 0) + dp[x + 2][0]) % mod;
    if (!x) dp[x][1] = (dp[x][1] + 1) % mod;
  }
  long long ans = 0;
  for (long long i = (0); i < (n + 1); ++i)
    ans = (ans + dp[i][0] + dp[i][1]) % mod;
  long long x = count((a).begin(), (a).end(), 1);
  x = (binpow<long long>(2, x) - 1 + mod) % mod;
  ans = (ans + x) % mod;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  for (long long ii = 1; ii <= tt; ii++) solve();
}
