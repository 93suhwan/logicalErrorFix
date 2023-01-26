#include <bits/stdc++.h>
using namespace std;
int dp[200010][33];
void generate() {
  for (long long i = 1; i <= (200000); i++) {
    for (long long j = 0; j < (32); j++) {
      dp[i][j] = dp[i - 1][j] + !((1 << j) & i);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  generate();
  int t;
  cin >> t;
  while (t--) {
    int l, r, mn = 0x3F3F3F3F;
    cin >> l >> r;
    for (long long j = 0; j < (32); j++) {
      mn = min(mn, dp[r][j] - dp[l - 1][j]);
    }
    cout << mn << '\n';
  }
  return 0;
}
