#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
void __print(long long x) { cerr << x; }
void __print(int32_t x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long N = 2e5 + 5;
const long long INF = 2e9;
const long double EPS = 1e-12;
const long double PI = 3.141592653589793116;
int32_t dp[505][505][505];
long long pre[505][2];
int32_t main() {
  std::ios_base::sync_with_stdio(0);
  cout.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  for (long long i = 0; i < m; i++) {
    string str = b.substr(0, i + 1);
    str.push_back('0');
    for (long long j = 0; j < (long long)str.size(); j++) {
      string tmp = str.substr(j);
      if ((long long)tmp.size() > (long long)b.size()) continue;
      if (tmp == b.substr(0, (long long)tmp.size())) {
        pre[i + 1][0] = (long long)tmp.size();
        break;
      }
    }
    str.pop_back();
    str.push_back('1');
    for (long long j = 0; j < (long long)str.size(); j++) {
      string tmp = str.substr(j);
      if ((long long)tmp.size() > (long long)b.size()) continue;
      if (tmp == b.substr(0, (long long)tmp.size())) {
        pre[i + 1][1] = (long long)tmp.size();
        break;
      }
    }
  }
  pre[0][0] = (b[0] == '0');
  pre[0][1] = (b[0] == '1');
  for (long long i = 0; i < 505; i++) {
    for (long long j = 0; j < 505; j++) {
      for (long long k = 0; k < 505; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      if (a[0] == '0') {
        dp[0][pre[i][1]][(pre[i][1] == m)] = 1;
        dp[0][pre[i][0]][(pre[i][0] == m)] = 0;
      } else {
        dp[0][pre[i][0]][(pre[i][0] == m)] = 1;
        dp[0][pre[i][1]][(pre[i][1] == m)] = 0;
      }
      continue;
    }
    for (long long j = 0; j <= m; j++) {
      for (long long k = 0; k <= n + m + 3; k++) {
        if (dp[i - 1][j][k] == INF) continue;
        int32_t &res0 = dp[i][pre[j][0]][k + (pre[j][0] == m)];
        int32_t &res1 = dp[i][pre[j][1]][k + (pre[j][1] == m)];
        res0 = min((int32_t)res0, dp[i - 1][j][k] + int32_t(a[i] != '0'));
        res1 = min((int32_t)res1, dp[i - 1][j][k] + int32_t(a[i] != '1'));
      }
    }
  }
  for (long long k = 0; k <= n - m + 1; k++) {
    int32_t ans = INF;
    for (long long j = 0; j <= m; j++) {
      ans = min(ans, dp[n - 1][j][k]);
    }
    if (ans == INF) ans = -1;
    cout << ans << ' ';
  }
  return 0;
}
