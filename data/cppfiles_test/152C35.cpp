#include <bits/stdc++.h>
using namespace std;
int it[1000001];
int dp[1000001][2];
pair<int, int> ba[1000001][2];
int ma[2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int st = 1;
    ma[0] = -1;
    ma[1] = 1;
    for (int i = 0; i < n; i++) {
      cin >> it[i];
      if (it[i] != (i + 1)) {
        st = 0;
      }
    }
    if (n <= 2 or st == 1) {
      cout << "YES" << '\n';
      for (int i = 0; i < n; i++) {
        cout << it[i] << " ";
      }
      cout << '\n';
      continue;
    }
    int xx = -(n + 1);
    dp[0][0] = xx;
    dp[0][1] = xx;
    ba[0][0] = {-1, -1};
    ba[0][1] = {-1, -1};
    for (int i = 1; i < n; i++) {
      dp[i][0] = n + 1;
      dp[i][1] = n + 1;
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          if (dp[i - 1][j] == n + 1) {
            continue;
          }
          if ((ma[k] * it[i]) > (ma[j] * it[i - 1])) {
            if (dp[i - 1][j] < dp[i][k]) {
              ba[i][k] = {i - 1, j};
            }
            dp[i][k] = min(dp[i][k], dp[i - 1][j]);
          }
          if ((it[i] * ma[k]) > dp[i - 1][j]) {
            if ((ma[j] * (it[i - 1])) < dp[i][k]) {
              ba[i][k] = {i - 1, j};
            }
            dp[i][k] = min(dp[i][k], (ma[j] * (it[i - 1])));
          }
        }
      }
    }
    if (dp[n - 1][0] == -xx and dp[n - 1][1] == -xx) {
      cout << "NO" << '\n';
    } else {
      pair<int, int> cur = {n - 1, 0};
      if (dp[n - 1][1] != -xx) {
        cur.second = 1;
      }
      cout << "YES" << '\n';
      vector<int> ans;
      while (cur.first >= 0) {
        ans.push_back(it[cur.first] * ma[cur.second]);
        cur = {ba[cur.first][cur.second].first,
               ba[cur.first][cur.second].second};
      }
      for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
