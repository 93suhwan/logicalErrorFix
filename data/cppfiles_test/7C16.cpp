#include <bits/stdc++.h>
using namespace std;
const int MAX = 500;
const int INF = 1e6;
int dp[2][MAX + 1][MAX + 1] = {0};
int nxt[MAX + 1][2];
int n, m;
string s, t;
void pre() {
  string pref = ".";
  for (int j = 0; j <= m; j++) {
    if (j) pref += t[j];
    {
      for (int c = 0; c <= 1; c++) {
        pref += '0' + c;
        int sz = (int)pref.size() - 1;
        nxt[j][c] = 0;
        for (int z = m; z >= 1; z--) {
          if (z <= sz) {
            if (t.substr(1, z) == pref.substr(sz - z + 1)) {
              nxt[j][c] = z;
              break;
            }
          }
        }
        pref.pop_back();
      }
    }
  }
}
void solve() {
  cin >> n >> m;
  cin >> s >> t;
  s = "." + s;
  t = "." + t;
  pre();
  dp[0][0][0] = 0;
  for (int j = 1; j <= n; j++) {
    for (int pref = 0; pref <= m; pref++)
      for (int k = 0; k <= n - m + 1; k++) dp[1][pref][k] = INF;
    for (int pref = 0; pref <= m; pref++) {
      for (int k = 0; k <= n - m + 1; k++) {
        for (int z = 0; z <= 1; z++) {
          if (nxt[pref][z] == m) {
            dp[1][nxt[pref][z]][k + 1] = min(dp[0][pref][k] + (s[j] != '0' + z),
                                             dp[1][nxt[pref][z]][k + 1]);
          } else {
            dp[1][nxt[pref][z]][k] =
                min(dp[0][pref][k] + (s[j] != '0' + z), dp[1][nxt[pref][z]][k]);
          }
        }
      }
    }
    for (int pref = 0; pref <= m; pref++)
      for (int k = 0; k <= n - m + 1; k++) dp[0][pref][k] = dp[1][pref][k];
  }
  for (int k = 0; k <= n - m + 1; k++) {
    int ans = INF;
    for (int z = 0; z <= m; z++) ans = min(ans, dp[0][z][k]);
    cout << (ans == INF ? -1 : ans) << ' ';
  }
  cout << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  for (int i = 0; i <= MAX; i++) {
    for (int k = 0; k <= MAX; k++) dp[0][i][k] = INF;
  }
  while (t--) {
    solve();
  }
  return 0;
}
