#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
const int MAXN = 5e2 + 10;
const int MOD = (int)1e9 + 7;
void clear() {}
void precalc() {}
int prefix[MAXN];
int dp[2][MAXN][MAXN];
void solve() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  for (int i = 1; i < b.size(); ++i) {
    int v = prefix[i - 1];
    while (v > 0 && b[v] != b[i]) v = prefix[v - 1];
    if (b[v] == b[i]) v++;
    prefix[i] = v;
  }
  int k = n - m + 1;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= m; j++) {
      dp[0][j][i] = (int)1e9;
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; j++) {
      for (int c = 0; c <= k; ++c) {
        dp[1][j][c] = (int)1e9;
      }
    }
    for (char l = '0'; l <= '1'; ++l) {
      int cost = l == a[i] ? 0 : 1;
      for (int j = 0; j <= m; j++) {
        int new_j = j;
        if (new_j == m) new_j = prefix[new_j - 1];
        while (new_j && b[new_j] != l) new_j = prefix[new_j - 1];
        if (b[new_j] == l) new_j++;
        int delta_k = new_j == m ? 1 : 0;
        for (int c = 0; c + delta_k <= k; c++) {
          dp[1][new_j][c + delta_k] =
              min(dp[1][new_j][c + delta_k], dp[0][j][c] + cost);
        }
      }
    }
    for (int j = 0; j <= m; j++) {
      for (int c = 0; c <= k; ++c) {
        dp[0][j][c] = dp[1][j][c];
      }
    }
  }
  for (int i = 0; i <= k; ++i) {
    int min_cost = (int)1e9;
    for (int j = 0; j <= m; j++) {
      min_cost = min(min_cost, dp[0][j][i]);
    }
    cout << (min_cost == (int)1e9 ? -1 : min_cost) << ' ';
  }
}
void multisolve() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  precalc();
  solve();
  return 0;
}
