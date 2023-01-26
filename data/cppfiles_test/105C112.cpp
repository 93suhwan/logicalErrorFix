#include <bits/stdc++.h>
using namespace std;
int inp[3010], a[3010], dp[3010][3010], _sf[3010][3010];
int n;
vector<int> pos[3010];
void solve() {
  cin >> n;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    pos[i].clear();
    cin >> inp[i];
    if (inp[i] != a[cur]) {
      cur++;
      a[cur] = inp[i];
    }
  }
  n = cur;
  for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) dp[i][j] = _sf[i][j] = 0;
  }
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] == a[j]) {
        _sf[i][j] = 1 + dp[i + 1][j];
        for (int _nxt : pos[a[i]]) {
          if (_nxt > i and _nxt < j)
            _sf[i][j] = max(_sf[i][j], 1 + dp[i + 1][_nxt] + dp[_nxt][j]);
        }
      }
      for (int _nxt : pos[a[i]]) {
        if (_nxt > i and _nxt < j)
          _sf[i][j] = max(_sf[i][j], 1 + dp[i + 1][_nxt] + dp[_nxt][j]);
      }
      dp[i][j] = max(dp[i + 1][j], _sf[i][j]);
      ans = max(ans, dp[i][j]);
    }
  }
  cout << n - 1 - ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
