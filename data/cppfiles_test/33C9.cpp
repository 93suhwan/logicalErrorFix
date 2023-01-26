#include <bits/stdc++.h>
using namespace std;
int ai[200010];
int dp[600];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> ai[i];
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[ai[i]] = min(dp[ai[i]], ai[i]);
    for (int j = 0; j <= 510; j++) {
      if (dp[j] <= ai[i]) dp[j ^ ai[i]] = min(dp[j ^ ai[i]], ai[i]);
    }
  }
  int res = 0;
  for (int i = 0; i <= 520; i++)
    if (dp[i] != 0x3f3f3f3f) res++;
  cout << res << endl;
  for (int i = 0; i <= 520; i++)
    if (dp[i] != 0x3f3f3f3f) cout << i << " ";
  cout << endl;
  return 0;
}
