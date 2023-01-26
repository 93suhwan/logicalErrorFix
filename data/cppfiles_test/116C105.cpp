#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
constexpr int MAXN = 5e5 + 2;
constexpr int MOD = 998244353;
constexpr long long INF = 1e18 + 10;
constexpr int LOG = 3e1 + 0;
constexpr int SQ = 2e3 + 20;
constexpr int ALP = 130;
int tc, n, a[MAXN], dp[MAXN][2];
int add(int a, int b) { return (a + b) % MOD; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      dp[a[i] + 2][1] = add(dp[a[i] + 2][1], dp[a[i] + 2][1]);
      if (a[i] == 0) {
        dp[a[i]][0] = add(dp[a[i]][0] * 2 % MOD, 1);
      } else if (a[i] == 1) {
        dp[a[i]][1] = add(dp[a[i]][1] * 2 % MOD, 1);
        dp[a[i]][0] = add(dp[a[i]][0] * 2 % MOD, dp[a[i] - 1][0]);
      } else {
        dp[a[i]][0] = add(dp[a[i]][0] * 2 % MOD, dp[a[i] - 1][0]);
        dp[a[i]][1] = add(dp[a[i]][1] * 2 % MOD, dp[a[i] - 2][0]);
      }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      ans = add(ans, dp[i][0]);
      ans = add(ans, dp[i][1]);
      dp[i][0] = 0;
      dp[i][1] = 0;
    }
    cout << ans << "\n";
  }
  return 0;
}
