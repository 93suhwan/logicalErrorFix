#include <bits/stdc++.h>
using namespace std;
string to_string(char c) { return string(1, c); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long inf = 2e18;
const double epsilon = 1e-7;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
inline long long gcd(long long a, long long b) {
  return (b == 0) ? a : gcd(b, a % b);
}
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
void solve() {
  long long n, ans = 0;
  cin >> n;
  vector<long long> v(n);
  for (long long i = (0); i < ((n)); ++i) cin >> v[i];
  long long dp[n + 5][2];
  memset(dp, 0, sizeof(dp));
  if (v[0] <= 1) {
    if (!v[0])
      dp[1][0] = 1;
    else
      dp[0][1] = 1;
  }
  for (long long i = (1); i < (n); ++i) {
    dp[v[i] + 1][1] = (dp[v[i] + 1][1] * 2) % 998244353;
    dp[v[i] + 1][0] = (2 * dp[v[i] + 1][0]) % 998244353;
    dp[v[i] + 1][0] = (dp[v[i] + 1][0] + dp[v[i]][0]) % 998244353;
    if (v[i]) dp[v[i] - 1][1] = (2 * dp[v[i] - 1][1]) % 998244353;
    if (v[i]) dp[v[i] - 1][1] = (dp[v[i] - 1][1] + dp[v[i] - 1][0]) % 998244353;
    if (!v[i])
      dp[1][0] = (dp[1][0] + 1) % 998244353;
    else if (v[i] == 1)
      dp[0][1] = (dp[0][1] + 1) % 998244353;
  }
  for (long long i = (0); i < ((n + 1)); ++i)
    ans = (ans + dp[i][0] + dp[i][1]) % 998244353;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  for (long long i = 1; i <= tt; i++) solve();
}
