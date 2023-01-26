#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, a[N];
int dp[8200];
vector<int> v[5500];
void solve() {
  cin >> n;
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  int m = 8193;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  for (int i = 0; i <= 5000; i++) {
    if (v[i].size() == 0) continue;
    dp[i] = min(dp[i], v[i][0]);
    for (int j = 0; j < m; j++)
      if (dp[j] <= v[i][v[i].size() - 1]) {
        int p = *lower_bound(v[i].begin(), v[i].end(), dp[j]);
        dp[j ^ i] = min(dp[j ^ i], p);
      }
  }
  vector<int> ans;
  for (int i = 0; i < m; i++)
    if (dp[i] <= n) ans.push_back(i);
  cout << ans.size() << endl;
  for (auto x : ans) cout << x << ' ';
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
