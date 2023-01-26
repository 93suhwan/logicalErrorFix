#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  const int MX = 2001;
  vector<vector<int>> dp(2, vector<int>(MX + 1, MX + 2));
  dp[0][0] = 0;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    dp[cur ^ 1].assign(MX + 1, MX + 2);
    int v;
    cin >> v;
    for (int j = 0; j < dp[cur].size(); ++j) {
      if (dp[cur][j] == MX + 2) {
        continue;
      }
      for (int mult : {-1, 1}) {
        int l = 0;
        int r = dp[cur][j];
        int nxt = j + mult * v;
        if (nxt < 0) {
          r += -nxt;
          nxt = 0;
        }
        if (nxt > r) {
          r = nxt;
        }
        if (nxt >= dp[cur].size()) continue;
        dp[cur ^ 1][nxt] = min(dp[cur ^ 1][nxt], r);
      }
    }
    cur ^= 1;
  }
  int mn = MX + 2;
  for (auto v : dp[cur]) {
    mn = min(mn, v);
  }
  cout << mn << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
}
