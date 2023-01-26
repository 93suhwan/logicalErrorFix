#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
const int MOD = 998244353;
const int MAXN = 3e3 + 100;
const int MAXK = 21;
const int LOGN = 20;
void clear() {}
void precalc() {}
void gen_tests() {}
vector<int> indexes[MAXN];
int dp[MAXN][MAXN];
int pos[MAXN];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    indexes[i].clear();
  }
  vector<int> values(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i];
    pos[i] = indexes[values[i]].size();
    indexes[values[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j + i < n; j++) {
      dp[j][i + j] = max(dp[j][i + j - 1], dp[j + 1][i + j]);
      int start_val = values[j];
      for (int c = pos[j];
           c < indexes[start_val].size() && indexes[start_val][c] <= i + j;
           ++c) {
        dp[j][i + j] =
            max(dp[j][i + j], dp[j][indexes[start_val][c]] +
                                  dp[indexes[start_val][c] + 1][i + j]);
      }
      if (start_val != values[i + j]) continue;
      for (int c = pos[j];
           c < indexes[start_val].size() && indexes[start_val][c] < i + j;
           ++c) {
        dp[j][i + j] =
            max(dp[j][i + j], 1 + dp[j][indexes[start_val][c]] +
                                  dp[indexes[start_val][c] + 1][i + j - 1]);
      }
    }
  }
  cout << n - dp[0][n - 1] - 1 << '\n';
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
  multisolve();
  return 0;
}
