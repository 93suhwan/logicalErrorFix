#include <bits/stdc++.h>
using namespace std;
inline long long md(long long m, long long v) { return ((v % m) + m) % m; }
const int MAX = 8500;
const int NOT = 1e7;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &_ : (arr)) cin >> _;
  vector<vector<int> > idx(MAX + 1);
  for (int i = 0; i < n; i++) {
    idx[arr[i]].push_back(i);
  }
  vector<bool> meet(MAX + 1);
  meet[0] = 1;
  for (int i : arr) meet[i] = 1;
  vector<vector<int> > dp(2, vector<int>(MAX + 1, NOT));
  dp[0][0] = -1;
  for (int a = 1; a <= MAX; a++) {
    int I = a % 2, J = 1 - I;
    if ((int)(idx[a]).size() == 0) {
      dp[I] = dp[J];
      continue;
    }
    dp[I][a] = min({dp[I][a], dp[J][a], idx[a].front()});
    int L = idx[a].back();
    for (int b = 0; b <= MAX; b++) {
      int target = a ^ b;
      if (target > MAX) continue;
      if (dp[J][target] < L) {
        dp[I][b] = min(dp[I][b],
                       idx[a][int(lower_bound((idx[a]).begin(), (idx[a]).end(),
                                              dp[J][target]) -
                                  begin(idx[a]))]);
        meet[b] = 1;
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i <= MAX; i++) {
    if (meet[i]) ans.push_back(i);
  }
  cout << (int)(ans).size() << "\n";
  for (int i : ans) cout << i << ' ';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
