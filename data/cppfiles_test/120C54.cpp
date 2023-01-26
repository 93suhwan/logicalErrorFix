#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 7, MOD = (int)1e9 + 7;
int l, r;
int dp[22][N];
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int i = 0; i <= 20; i++) {
    for (int j = 1; j <= 2e5 + 500; j++) {
      dp[i][j] = dp[i][j - 1];
      if ((j & (1 << i))) dp[i][j]++;
    }
  }
  while (T--) {
    cin >> l >> r;
    int ans = r - l + 1;
    for (int i = 0; i <= 20; i++) {
      int cnt = dp[i][r] - dp[i][l - 1];
      ans = min(ans, r - l + 1 - cnt);
    }
    cout << ans << "\n";
  }
  exit(0);
}
