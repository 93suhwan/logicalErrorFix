#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 7;
const int MOD = 1e9 + 7;
int t, n;
int v[17], dp[17][2][2];
int cal(int x, int op) {
  if (op == 0)
    return x + 1;
  else
    return 9 - x;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    int tol = 0;
    while (n) {
      v[++tol] = n % 10;
      n /= 10;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1; i <= tol; i++) {
      dp[i][0][0] =
          cal(v[i] - 1, 0) * dp[i - 1][0][1] + cal(v[i], 0) * dp[i - 1][0][0];
      dp[i][0][1] =
          cal(v[i] - 1, 0) * dp[i - 1][1][1] + cal(v[i], 0) * dp[i - 1][1][0];
      dp[i][1][0] =
          cal(v[i] - 1, 1) * dp[i - 1][0][1] + cal(v[i], 1) * dp[i - 1][0][0];
      dp[i][1][1] =
          cal(v[i] - 1, 1) * dp[i - 1][1][1] + cal(v[i], 1) * dp[i - 1][1][0];
    }
    cout << dp[tol][0][0] - 2 << '\n';
  }
  return 0;
}
