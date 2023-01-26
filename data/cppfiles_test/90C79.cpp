#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MOD = 998244353;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> pts(n + 2);
  pts[0] = -INF;
  pts[n + 1] = INF;
  for (long long i = 1; i <= n; i++) cin >> pts[i];
  sort(pts.begin(), pts.end());
  vector<vector<pair<long long, long long>>> invls(n + 2);
  for (long long i = 0; i < m; i++) {
    long long l, r;
    cin >> l >> r;
    long long ind = lower_bound(pts.begin(), pts.end(), l) - pts.begin();
    ;
    if (pts[ind] <= r) continue;
    invls[ind - 1].push_back({l, r});
  }
  vector<vector<long long>> dp(2, vector<long long>(n + 2, INF));
  dp[0][0] = dp[1][0] = 0;
  for (long long i = 0; i < n + 1; i++) {
    invls[i].push_back({pts[i], pts[i]});
    invls[i].push_back({pts[i + 1], pts[i + 1]});
    sort(invls[i].begin(), invls[i].end());
    long long k = (long long)invls[i].size();
    k--;
    dp[0][i + 1] = dp[1][i + 1] = INF;
    long long mx = INF;
    ;
    while (k > 0) {
      mx = min(mx, invls[i][k].second);
      dp[0][i + 1] = min(
          {dp[0][i + 1],
           dp[0][i] + 2ll * (pts[i + 1] - mx) + invls[i][k - 1].first - pts[i],
           dp[1][i] + 2ll * (pts[i + 1] - mx) +
               2ll * (invls[i][k - 1].first - pts[i])});
      dp[1][i + 1] =
          min({dp[1][i + 1],
               dp[0][i] + (pts[i + 1] - mx) + invls[i][k - 1].first - pts[i],
               dp[1][i] + (pts[i + 1] - mx) +
                   2ll * (invls[i][k - 1].first - pts[i])});
      ;
      k--;
    }
  }
  cout << dp[1][n + 1] << "\n";
}
int32_t main() {
  ios::sync_with_stdio(!cin.tie(NULL));
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
