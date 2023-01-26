#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<vector<int>> idx(5001);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    idx[A[i]].push_back(i);
  }
  for (int i = 0; i <= 5000; ++i) {
    sort(idx[i].begin(), idx[i].end());
  }
  vector<int> dp(8192, -1);
  dp[0] = 1e9;
  for (int v = 5000; v >= 0; --v) {
    if (idx[v].empty()) continue;
    for (int t = 0; t < 8192; ++t) {
      int id = dp[t ^ v];
      if (id == -1) continue;
      auto it = lower_bound(idx[v].begin(), idx[v].end(), id);
      if (it == idx[v].begin()) continue;
      it = prev(it);
      dp[t] = max(*it, dp[t]);
    }
  }
  int cnt = 0;
  for (int t = 0; t < 8192; ++t)
    if (dp[t] != -1) cnt++;
  cout << cnt << endl;
  for (int t = 0; t < 8192; ++t)
    if (dp[t] != -1) cout << t << " ";
  cout << endl;
}
