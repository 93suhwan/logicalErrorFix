#include <bits/stdc++.h>
using namespace std;
const int N = 800008;
const long long M = 1000000007;
int dp[20][N];
void init() {
  for (int i = 1; i <= 200000; i++) {
    for (int j = 0; j < 20; j++) {
      if ((i & (1 << j)) > 0) {
        dp[j][i] = dp[j][i - 1] + 1;
      } else {
        dp[j][i] = dp[j][i - 1];
      }
    }
  }
}
void solve() {
  int l, r;
  cin >> l >> r;
  int ans = r - l;
  for (int i = 0; i < 20; i++) {
    int cnt = dp[i][r] - dp[i][l - 1];
    ans = min(ans, r - l + 1 - cnt);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  int tc = 1;
  cin >> tc;
  for (int qq = 1; qq <= tc; qq++) {
    solve();
  }
  return 0;
}
