#include <bits/stdc++.h>
using namespace std;
const int A = 5e3 + 5, K = 1 << 13;
int n, dp[A][K];
vector<int> pos[A];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n;
  for (int i = 0; i < (A); ++i) {
    for (int j = 0; j < (K); ++j) {
      dp[i][j] = n;
    }
  }
  dp[0][0] = -1;
  for (int i = 0; i < (n); ++i) {
    int a;
    cin >> a;
    pos[a].push_back(i);
  }
  for (int i = 1; i < (A); ++i) {
    for (int j = 0; j < (K); ++j) {
      dp[i][j] = dp[i - 1][j];
      auto it = lower_bound(begin(pos[i]), end(pos[i]), dp[i - 1][j ^ i]);
      if (it != end(pos[i])) {
        dp[i][j] = min(dp[i][j], *it);
      }
    }
  }
  vector<int> ans;
  for (int j = 0; j < (K); ++j) {
    if (dp[A - 1][j] < n) {
      ans.push_back(j);
    }
  }
  cout << (int)(ans).size() << '\n';
  for (const int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}
