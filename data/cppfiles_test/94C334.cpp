#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void rset();
void init_test();
void solve();
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(20);
  init_test();
  return 0;
}
template <typename T>
void chmin(T& a, T b) {
  if (a > b) a = b;
}
template <typename T>
void chmax(T& a, T b) {
  if (a < b) a = b;
}
template <typename T>
void MACRO_rdv2_Init(long long n, T& t) {
  t.resize(n);
}
template <typename First, typename... Rest>
void MACRO_rdv2_Init(long long n, First& first, Rest&... rest) {
  first.resize(n);
  MACRO_rdv2_Init(n, rest...);
}
template <typename T>
void MACRO_rdv2_Scan(long long p, T& t) {
  std::cin >> t[p];
}
template <typename First, typename... Rest>
void MACRO_rdv2_Scan(long long p, First& first, Rest&... rest) {
  std::cin >> first[p];
  MACRO_rdv2_Scan(p, rest...);
}
template <typename T>
void wrv(const vector<T>& v) {
  for (long long(__ii) = (0); (__ii) < (((long long)v.size())); ++(__ii)) {
    if (__ii) cout << ' ';
    cout << v[__ii];
  }
  cout << '\n';
}
template <typename T>
void wrm(const vector<vector<T>>& v) {
  for (long long(__ii) = (0); (__ii) < (((long long)v.size())); ++(__ii)) {
    for (long long(__jj) = (0); (__jj) < (v[__ii].size()); ++(__jj)) {
      if (__jj) cout << ' ';
      cout << v[__ii][__jj];
    }
    cout << '\n';
  }
}
template <typename T>
void sc(T& x) {
  cin >> x;
}
template <typename Head, typename... Tail>
void sc(Head& head, Tail&... tail) {
  cin >> head;
  sc(tail...);
}
template <typename T>
void wr(const T& x) {
  cout << x << '\n';
}
template <typename Head, typename... Tail>
void wr(const Head& head, const Tail&... tail) {
  cout << head << ' ';
  wr(tail...);
}
template <typename T>
void wrf(const T& x) {
  cout << x << endl;
}
template <typename Head, typename... Tail>
void wrf(const Head& head, const Tail&... tail) {
  cout << head << ' ';
  wrf(tail...);
}
template <typename T>
void debug_out(const T& x) {
  cerr << x << '\n';
}
template <typename Head, typename... Tail>
void debug_out(const Head& head, const Tail&... tail) {
  cerr << head << ' ';
  debug_out(tail...);
}
template <typename... T>
void err(const T&... cod) {
  wr(cod...);
  exit(0);
}
const long long LEN = 41;
const long long CUR = 2;
const long long NXT = 2;
vector<long long> d;
long long n;
long long dp[LEN][CUR][NXT];
vector<long long> to_vec(long long n) {
  vector<long long> a;
  while (n > 0) {
    a.push_back(n % 10);
    n /= 10;
  }
  reverse(a.begin(), a.end());
  return a;
}
long long f(long long at, long long cur, long long nxt) {
  if (at < 0) return (cur == 0 && nxt == 0 ? 1 : 0);
  if (dp[at][cur][nxt] != -1) return dp[at][cur][nxt];
  long long ans = 0;
  for (long long(i) = (0); (i) < (10); ++(i))
    for (long long(j) = (0); (j) < (10); ++(j)) {
      if ((i + j + cur) % 10 == d[at]) {
        ans += f(at - 1, nxt, (i + j + cur) > 9);
      }
    }
  return dp[at][cur][nxt] = ans;
}
void solve() {
  memset(dp, -1, sizeof dp);
  cin >> n;
  d = to_vec(n);
  wr(f(((long long)d.size()) - 1, 0, 0) - 2);
}
void init_test() {
  long long qq = 1;
  cin >> qq;
  while (qq--) solve();
}
