#include <bits/stdc++.h>
using namespace std;
const int MAX = 3005;
vector<int> col[MAX];
int cnt = 0;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) col[i].clear();
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    col[v[i]].push_back(i);
  }
  for (int lt = n; lt >= 1; lt--) {
    for (int rt = lt; rt <= n; rt++) {
      if (lt == rt) continue;
      int a = dp[lt][rt - 1];
      int b = dp[lt + 1][rt];
      if (v[lt] != v[rt] && v[rt - 1] != v[rt]) a++;
      if (v[lt] != v[lt + 1] && v[lt] != v[rt]) b++;
      dp[lt][rt] = min(a, b);
      int c = v[lt];
      for (int i = 0; i < col[c].size(); i++) {
        int x = col[c][i];
        if (x <= lt) continue;
        if (x >= rt) break;
        dp[lt][rt] = min(dp[lt][rt], dp[lt][x] + dp[x + 1][rt] + 1);
      }
      c = v[rt];
      for (int i = 0; i < col[c].size(); i++) {
        int x = col[c][i];
        if (x <= lt) continue;
        if (x >= rt) break;
        dp[lt][rt] = min(dp[lt][rt], dp[lt][x - 1] + dp[x][rt] + 1);
      }
    }
  }
  cout << dp[1][n] << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
