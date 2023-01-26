#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
string to_string(char s) {
  string res = "'''";
  res[1] = s;
  return res;
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = 1;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug() { cout << "\n"; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug(T...);
}
const int MOD = 1e9 + 7;
inline int add(int a, int b, int p = MOD) {
  a = a + b;
  if (a >= p) a -= p;
  return a;
}
inline int sub(int a, int b, int p = MOD) {
  a = a - b;
  if (a < 0) a += p;
  return a;
}
inline int mul(int a, int b, int p = MOD) {
  a = (a * 1ll * b) % p;
  return a;
}
const ld pi = acos(-1), eps = 1e-9;
const ll inf = 1e9;
const int N = 1e4 + 5, M = 2e3 + 5;
int dp[N][M];
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < (n); ++i) cin >> v[i];
  int mx = 2 * (*max_element(begin(v), end(v)));
  for (int i = 0; i < (n + 1); ++i) {
    for (int j = 0; j < (mx + 1); ++j) dp[i][j] = inf;
  }
  dp[0][0] = 0;
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j + v[i] <= mx; ++j) {
      if (dp[i][j] == inf) continue;
      dp[i + 1][max(0, j - v[i])] =
          min(dp[i + 1][max(0, j - v[i])], dp[i][j] + v[i]);
      dp[i + 1][j + v[i]] = min(dp[i + 1][j + v[i]], max(0, dp[i][j] - v[i]));
    }
  }
  int ans = inf;
  for (int i = 0; i < (mx + 1); ++i) ans = min(ans, i + dp[n][i]);
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t = 1;
  cin >> t;
  for (int z = 1; z <= t; ++z) {
    solve();
    cout << "\n";
  }
  return 0;
}
