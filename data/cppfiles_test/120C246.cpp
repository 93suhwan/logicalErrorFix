#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int MAXN = 2 * 1e5 + 7;
  vector<vector<int> > dp(20, vector<int>(MAXN, 0));
  for (int i = 1; i < MAXN; i++) {
    for (int j = 0; j < 20; j++) {
      dp[j][i] = dp[j][i - 1] + bool(i & (1 << j));
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int maxi = 0;
    for (int i = 0; i < 20; i++) {
      maxi = max(maxi, dp[i][r] - dp[i][l - 1]);
    }
    cout << r - l + 1 - maxi << "\n";
  }
  return 0;
}
