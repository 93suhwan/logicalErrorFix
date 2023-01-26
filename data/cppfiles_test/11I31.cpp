#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
const int inf = 1e9;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int dp[n + 1];
  for (int i = 0; i <= n; i++) dp[i] = -inf;
  dp[0] = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i], 0);
    if (a[i] > n) continue;
    dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
    ans = max(ans, dp[a[i]]);
  }
  cout << ans << endl;
}
